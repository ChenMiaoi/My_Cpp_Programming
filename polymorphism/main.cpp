#include <iostream>

using namespace std;

/*
	多态 -- 多种形态
	静态的多态 -- 函数重载
	动态的多态 -- 父类指针或引用调用重写虚函数
	1. 父类指针或者引用指向父类，调用的就是父类的虚函数
	2. 父类指针或者引用指向哪一个子类，调用的就是子类的虚函数 
		不同的类型对象，去完成同一件事情，产生的动作是不一样的，结果也是不一样的

	条件：(缺一不可)
	1. 必须通过基类的指针或者引用调用虚函数
	2. 被调用的函数必须是虚函数，并且虚函数要完成重载
*/

//int main()
//{
//	int i;
//	char ch;
//
//	cin >> i;
//	cin >> ch;
//
//	cout << i << endl;
//	cout << ch << endl; 
//	cout << ch << endl;
//}

//注意：
/*
	1.只有类的非静态成员函数可以是虚函数
	2.虚函数这里virtual和虚继承中的virtual是同一个关键字，但是他们之间没有任何关系
		虚函数是为了实现多态
		虚继承是为了解决菱形继承的数据冗余和二义性
*/

/*
	虚函数的重写：
		派生类中有一个跟基类完全相同的虚函数(即派生类虚函数与基类虚函数的返回值类
型、函数名字、参数列表完全相同)，称子类的虚函数重写了基类的虚函数。
*/
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票 全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票 半价" << endl;
//	}
//};
//
//class Soldier : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "优先 买票" << endl;
//	}
//};
//
//void f(Person& p)
//{
//	//传不同类型的对象，调用的是不同的函数，实现了调用的多种形态
//	p.BuyTicket();
//}
//
//void f(Person* p)
//{
//	p->BuyTicket();
//}

//int main()
//{
//	Person p;	//普通人
//	Student s;	//学生
//	Soldier so;	//军人
//	
//	f(p);
//	f(s);
//	f(so);
//	cout << endl;
//	f(&p);
//	f(&s);
//	f(&so);
//}

//虚函数重写的例外：
//1. 协变 -- 基类与派生类虚函数返回值类型不同 -- 且返回值是父子关系的指针或引用
//但是必须是基类返回基类指针或引用，派生类返回派生类指针或引用
//class A{};
//class B : public A{};
//
//class Person
//{
//public:
//	virtual A* f()
//	{
//		cout << "A* Person::f()" << endl;
//		return new A;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual B* f()
//	{
//		cout << "B* Student::f()" << endl;
//		return new B;
//	}
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	Person* ptr;
//	ptr = &p;
//	ptr->f();
//
//	ptr = &s;
//	ptr->f();
//}

//2.析构函数重写
//class Person
//{
//public:
//	//建议把父类析构函数定义为虚函数，这样子类的虚函数方便重写父类虚函数
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	{
//		//student和person析构函数的函数名看起来不相同，但是他们构成虚函数重写
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	//在普通场景下，父子类的析构函数是否构成重写，不重要，没有影响
//	/*Person p;
//	Student s;*/
//
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	//如果没有虚析构，那么这里的p2指向的子类对象，应该调用子类析构，但是没有调用，可能内存泄露
//	delete p1;
//	delete p2;
//	//只有析构函数重写了，那么这里delete父类指针，调用析构函数，才能实现多态
//	//指向父类，调用父类析构函数
//	//指向子类，调用子类析构函数
//	//才能实现正确调用
//}


//final关键字，不让基类的虚函数被重写
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{
//	
//}

//override 检查子类的虚函数是否完成重写
//class Car {
//public:
//	virtual void Drive() {}
//};
//
//class Benz :public Car {
//public:
//	virtual void Drive(int i) override { cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{
//
//}

//抽象类
//包含纯虚函数的类叫做抽象类 -- 不能实例化出对象
//可以更好的去表示现实世界中，没有实例对象对应的抽象类型
//体现接口继承，强制子类去重写虚函数(不重写子类也是抽象类)
//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz" << endl;
//	}
//};
//
//class BMW : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW" << endl;
//	}
//};
//
//int main()
//{
//	Car* benz = new Benz;
//	benz->Drive();
//
//	Car* bmw = new BMW;
//	bmw->Drive();
//}

/*
	这里跟虚继承不一样的，他们之间都用了virtual关键字，但是使用场景完全不一样，解决的问题
	也是不一样的，他们之间没有关联
	虚继承产生叫做虚基表，虚基表里面存储的是虚继承的偏移量
*/

//class Base
//{
//public:
//	virtual void func()
//	{}
//private:
//	int _a = 1;
//	char _ch = '\0';
//};
//
///*
//	满足多态条件以后，构成多态：
//		指针或者引用，调用虚函数时，不是编译时确定的，是运行时到指向的对象中的虚表
//		中去找对应虚函数调用，所以指向的父类对象，调用的就是父类的虚函数，指向的是子类的
//		对象，调用的就是子类的虚函数
//
//	如果不构成多态：
//		就是编译时确定对应的函数方法
//*/
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//}

//为什么必须要引用或指针？
//因为切片操作不会将对象的虚表切过去，而引用或指针可以

//单继承
//class Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "Base::func2()" << endl;
//	}
//};
//
//class Drive : public Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Drive::func1()" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "Drive::func3()" << endl;
//	}
//	virtual void func4()
//	{
//		cout << "Drive::func4()" << endl;
//	}
//};
//
//typedef void(*VFunc)();
//
////打印虚表
//void PrintVFT(VFunc* ptr)	//存函数指针的数组指针 -- VFunc ptr[]
//{
//	printf("虚表地址 : %p\n", ptr);
//	for (int i = 0; ptr[i] != nullptr; ++i)
//	{
//		printf("VFT[%d] : %p\n", i, ptr[i]);
//		ptr[i]();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Base b;
//	PrintVFT((VFunc*)(*(int*)&b));
//	Drive d;
//	PrintVFT((VFunc*)(*(int*)&d));
//}

//多继承
class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main()
{
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);
	return 0;
}