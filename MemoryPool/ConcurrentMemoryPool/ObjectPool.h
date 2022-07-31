#ifndef CONCURRENTMEMORYPOOL_OBJECTPOOL_H
#define CONCURRENTMEMORYPOOL_OBJECTPOOL_H

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// 定长内存池
//template <size_t N>
//class ObjetctPool{
//
//};

inline static void* SystemAlloc(size_t kpage){
#ifdef _WIN32
    void* ptr = VirtualAlloc(0, kpage*(1 << 12), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
    //linux brk、mmap等
    void* ptr = (void*) malloc(kpage);
#endif
    if (ptr == nullptr){
        throw std::bad_alloc();
    }
    return ptr;
}

template <class T>
class ObjectPool{
public:
    T* New(){
        T* obj = nullptr;
        //优先把还回来的内存块重复利用
        if (_freeList != nullptr){
            void* next = *((void**)_freeList);
            obj = (T*)_freeList;
            _freeList = next;
        }else {
            if (_remainBytes < sizeof(T)){  //连一个对象的内存空间都不足了，需要重新开辟一个大空间
                _remainBytes = 128 * 1024;  //初始化剩余空间
                //_memory = (char*)malloc(_remainBytes);
                _memory = (char*)SystemAlloc(_remainBytes);
                if (_memory == nullptr){
                    throw std::bad_alloc();
                }
            }
            obj = (T*)_memory;
            //解决如果类型大小小于一个指针大小的问题
            size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);
            _memory += objSize;
            _remainBytes -= objSize;
        }

        //定位new,显示调用T的构造函数初始化
        new(obj)T;
        return obj;
    }

    void Delete(T* obj){
        //显示调用析构函数
        obj->~T();

        //为什么要强转为void*，因为void*是四个字节(32位)，刚好可以存放下指针，也就是强转为void*，将内存前四个字节变为指针域
        *(void**)obj = _freeList;
        _freeList = obj;
        /*
        if (_freeList == nullptr){
            _freeList = obj;        //使freelist与回收的内存建立链接
            //*(int**)obj = nullptr;
            *(void**)obj = nullptr; //void* 在32位下是4个字节，在64位是8个字节，可以有效的解决兼容性问题
            //让最后的尾巴指向空
        } else{
            //使用头插
            *(void**)obj = _freeList;
            _freeList = obj;
        }
         */
    }
private:
    char* _memory = nullptr;    //指向大块内存的指针
    void* _freeList = nullptr;  //还回过程中链接的自由链表头指针
    size_t _remainBytes = 0;    //大块内存在切分过程中剩余字节数
};

#endif //CONCURRENTMEMORYPOOL_OBJECTPOOL_H
