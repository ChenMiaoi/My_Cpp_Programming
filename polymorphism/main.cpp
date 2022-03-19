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

