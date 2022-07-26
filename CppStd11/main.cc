#include <iostream>
#include <initializer_list>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <cctype>

using namespace std;

#if 0
struct Point{
    int _x;
    int _y;
};

/*
 * 虽然C++11之后可以去掉赋值符号，但是类似于普通变量、数组的时候，最好还是使用C++98风格
 * */
int main() {
    Point p1 = {1, 2};
    Point p2{1, 2};
    int x1 = 1;
    int x2{1};
    int* p3 = new int[4]{0};
    int* p4 = new int[4]{1, 2, 3, 4};
    return 0;
}
#endif

class Date{
public:
    Date(int year = 0, int month = 0, int day = 0)
            : _year(year)
            , _month(month)
            , _day(day)
    {}
private:
    int _year;
    int _month;
    int _day;
};

#if 0

int main(){
    Date d1;
    Date d2(2022, 6, 13);
    //列表初始化，会调用构造函数
    Date d3{2022, 6, 13};
    return 0;
}
#endif

//initializer_list
//使{}初始化场景进行扩大

#if 0
int main(){
    auto il = {1, 2, 3, 4};
    cout << typeid(il).name() << endl;

    vector<int> v = {1, 2, 3, 4, 5};
    list<int> l {10 ,20 ,30, 40};
    vector<Date> vd = {Date(2022, 6, 13), Date(2022, 6, 14)};
    map<string, int> {make_pair("sort", 1), {"insert", 2}};
    return 0;
}
#endif

#if 0
namespace myinitial{
    template <class T>
    class Vector{
    public:
        typedef T* iterator;

        Vector(initializer_list<T> l){
            _start = new T[l.size()];
            _finish = _start + l.size();
            _end = _start + l.size();

            iterator vit = _start;
            /*
            typename initializer_list<T>::iterator lit = l.begin();
            while (lit != l.end()) {
                *vit++ = *lit++;
            }
            */
            for (auto e : l){
                *vit++ = e;
            }
        }

        Vector<T>& operator= (initializer_list<T> l){
            Vector<T> temp(1);
            std::swap(_start, temp._start);
            std::swap(_finish, temp._finish);
            std::swap(_end, temp._end);
            return *this;
        }

    private:
        iterator _start;
        iterator _end;
        iterator _finish;
    };
}

int main(){
    myinitial::Vector<int> v = {1, 2, 3, 4};
    return 0;
}
#endif

#if 0

int main(){
    /*
    int i = 10;
    auto p  = &i;
    auto pf = strcpy;

    cout << typeid(p).name() << endl;
    cout << typeid(pf).name() << endl;

    decltype(pf) px;
     */
    const int x = 10;
    double y = 2.2;
    decltype(x * y) ret;
    decltype(&x) p;
    cout << typeid(ret).name() << endl;
    cout << typeid(p).name() << endl;
    return 0;
}
#endif

#if 0
#include <array>
#include <forward_list>
int main(){
    array<int, 10> a1;
    array<int, 20> a2;
    //对于越界标准更严格，其他的和普通数组没区别。。。
    return 0;
}
#endif

#if 0
/*
 * 右值是一个表示数据的表达式，如：字面常量， 表达式返回值， 函数返回值(这个不能是左值引用返回)等
 * 右值引用之后，会导致右值存储到一个特定的位置，且可以取到该位置的地址
 * */
int main(){
    double x = 1.1, y = 2.2;

    int&& r1 = 10;
    double&& r2 = x + y;
    double&& r3 = fmin(x, y);

    cout << r1 << endl;
    cout << r2 << endl;
    cout << r3 << endl;
    return 0;
}
#endif

#if 0

void Fun(int& x){ std::cout << "左值引用" << std::endl;}
void Fun(const int& x) { std::cout << "const 左值引用" << std::endl;}

void Fun(int&& x) { std::cout << "右值引用" << std::endl;}
void Fun(const int&& x) { std::cout << "const 右值引用" << std::endl;}

template <typename T>
void PerfectForward(T&& t){
    Fun(std::forward<T>(t));
}

int main(){
    PerfectForward(10);

    int a;
    PerfectForward(a);
    PerfectForward(std::move(a));

    const int b = 8;
    PerfectForward(b);
    PerfectForward(std::move(b));
    return 0;
}
#endif // !0

#if 0
template <class T1, class T2>
auto F(T1 x, T2 y) -> decltype(x * y){
    decltype(x * y) ret = x * y;
    return ret;
}
int main(){
    auto ret = F(1, 2.1);
    std::cout << ret << std::endl;
    return 0;
}
#endif // !0

void ShowList(){}

//template <class T, class ...Args>
//void ShowList(T value, Args... args){
//    //cout << sizeof...(args) << endl;
//    cout << value << endl;
//    ShowList(args...);
//}
//
//int main(){
//    char ch[7] = {"65ab21"};
//    for (int i = 0; ch[i] >= '0' && ch[i] <= '9'; i++){
//        printf("%c", ch[i]);
//    }
//    return 0;
//}

struct Goods{
    string _name;
    double _price;
    int _num;
};

struct Compare{
    bool operator()(const Goods& g1, const Goods& g2){
        return g1._price <= g2._price;
    }
};

int main(){
    vector<Goods> gds = {
            {"苹果", 2.1, 300},
            {"香蕉", 3.3, 100},
            {"橙子", 2.2, 1000}
    };
    std::sort(gds.begin(), gds.end(), [](const Goods& g1, const Goods& g2)->bool {
        return g1._price < g2._price;

    })
    //std::sort(gds.begin(), gds.end(), Compare());
    //lambda表达式
    /*
     * [capture-list](parameters)multable->return-type{statement}
     * 捕捉列表：总是在lambda表达式函数开始的位置，编译器根据[]来判断接下来的代码是否为lambda,且能够捕捉上下文的变量供lambda使用
     * 参数列表：与普通的传参一样，若没有参数，可以省略()
     * mutable：默认情况下，lambda总是一个const函数，mutable可以取消其常量性，使用该参数时，参数列表不可省略
     *
     * 最简单的lambda表达式：[]{}
     * */
    []{};
    int a = 1, b = 2;
    //实现add的lambda
    auto add = [](int x, int y)->int {return x + y;};
    cout << add(a, b) << endl;

    auto add1 = [a, b]()->int {return a + b + 10;};
    cout << add1() << endl;
    return 0;
}
