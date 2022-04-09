#include <iostream>

using namespace std;

/*
	请设计一个类，只能在堆上创建对象
		实现方式：
		1. 将类的构造函数私有，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。
		2. 提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建
*/
#if 0
class HeapOnly
{
public:
	static HeapOnly* CreatObj()	//需要设置为静态，不然没有对象无法调用成员函数
	{
		return new HeapOnly;
	}
private:
	HeapOnly()	//将构造设置为私有，限制了常规对象的存在
	{}
	HeapOnly(const HeapOnly&);	//声明拷贝构造私有，并且不实现，这样隔绝了栈区对象的生成 -- 防拷贝C++98

	//C++11
	HeapOnly(const HeapOnly&) = delete;
};

int main()
{
	HeapOnly* p = HeapOnly::CreatObj();
	return 0;
}
#endif // !0 创建一个只能在堆区建立的类

/*
	请设计一个类，只能在栈上创建对象
		方法一：同上将构造函数私有化，然后设计静态方法创建对象返回即可
		方法二：屏蔽new,因为new在底层调用void* operator new(size_t size)函数，只需将该函数屏蔽掉即可。
			注意：也要防止定位new
*/
#if 0
class StackOnly
{
public:
	static StackOnly CreatObj()
	{
		return StackOnly();
	}
private:
	StackOnly() {}
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
};

int main()
{
	StackOnly sto = StackOnly::CreatObj();
}
#endif // !0 创建一个只能在栈区建立的类

/*
	请设计一个类，不能被拷贝
		拷贝只会放生在两个场景中：拷贝构造函数以及赋值运算符重载，因此想要让一个类禁止拷贝，只需让该类
		不能调用拷贝构造函数以及赋值运算符重载即可
		C++98
			将拷贝构造函数与赋值运算符重载只声明不定义，并且将其访问权限设置为私有即可
			原因：
				1. 设置成私有：如果只声明没有设置成private，用户自己如果在类外定义了，就可以不能禁止拷贝了
				2. 只声明不定义：不定义是因为该函数根本不会调用，定义了其实也没有什么意义，不写反而还简
					单，而且如果定义了就不会防止成员函数内部拷贝了
		C++11
			C++11扩展delete的用法，delete除了释放new申请的资源外，如果在默认成员函数后跟上=delete，表
			示让编译器删除掉该默认成员函数
*/

/*
	请设计一个类，不能被继承
		C++98
			将构造函数私有化，派生类中调不到基类的构造函数，则无法继承
			父类私有成员在子类不可见
		C++11
			新增一个final关键字，使用final关键字
*/
#if 0
class Base final
{
private:
	Base()
	{}
};

//C++98中这个不能被继承的方式不够彻底，实际上是可以继承，限制的是子类继承后不能实例化对象
class Child : public Base
{

};

int main()
{
	Child d;
}
#endif // !0 不能被继承的类


//单例模式  
/*
	1.如何保证全局(一个进程中)只有一个唯一实例对象
		a.构造函数私有定义，拷贝构造和赋值防拷贝禁掉
		b.提供一个GetInstance获取单例对象

	饿汉模式：提供一个静态只想单例对象的成员指针，初始化时new一个对象给他(程序开始，main执行之前就创建了单例对象)
	懒汉模式：
*/

#if 0
//饿汉模式
class Signleton
{
public:
	static Signleton* GetInstance()
	{
		return _inst;
	}
private:
	Signleton()
	{}

	Signleton(const Signleton&) = delete;
	Signleton& operator= (const Signleton&) = delete;

	static Signleton* _inst;
};

Signleton* Signleton::_inst = new Signleton;

int main()
{
	//全局唯一实例对象
	cout << Signleton::GetInstance() << endl;
	cout << Signleton::GetInstance() << endl;
	cout << Signleton::GetInstance() << endl;
}
#endif // !0 饿汉模式

//懒汉模式
class Signleton
{
public:
	static Signleton* GetInstance()
	{
		if (_inst == nullptr)
			_inst = new Signleton;
		return _inst;
	}
private:
	Signleton()
	{	
		//假设单例类中构造函数需要做很多初始化工作，导致程序启动非常慢
	}

	Signleton(const Signleton&) = delete;
	Signleton& operator= (const Signleton&) = delete;

	static Signleton* _inst;
};

Signleton* Signleton::_inst = nullptr;

int main()
{
	//全局唯一实例对象
	cout << Signleton::GetInstance() << endl;
	cout << Signleton::GetInstance() << endl;
	cout << Signleton::GetInstance() << endl;
}