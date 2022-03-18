#include <iostream>
#include <string>

using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name: " << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//protected:
//	string _name = "peter";
//	int _age = 18;
//};
//
//class Stu : public Person
//{
//protected:
//	int _stuid;
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid;
//};

//继承权限永远只能向小的继承
// public > projected > private

//父类的私有成员继承下来不可见的意思是：
//内存上，子类对象有这个成员，但是语法规定上我们不能去访问

//int main()
//{
//	Stu s;
//	s.Print();
//
//	Teacher t;
//	t.Print();
//	return 0;
//}

//赋值兼容规则 -- 切片
//class Person
//{
//protected:
//	string _name;
//	string _sex;
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	int _num;
//};
//
//int main()
//{
//	Person p;
//	Student s;
//
//	//子类可以赋值给父类，父类不可以赋值给子类
//	//子类给父类的过程，叫做切片操作(多给少)
//	/*p = s;
//	s = p;*/
//
//	Person* ptr = &s;
//	Person& ref = s;
//}

//子类成员屏蔽父类对同名成员的直接访问，这种情况叫做隐藏，也叫做重定义
//class A
//{
//public:
//	void fun()
//	{
//		cout << "fun()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)" << endl;
//	}
//};
//int main()
//{
//	B b;
//	b.fun(10);
//}

//class Person
//{
//public :
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()	//因为 -> 后面多态的一些原因，任何类析构函数名都会被统一处理成destructor
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int id)
//		: Person(name)
//		, _id(id)
//	{
//		//调用父类构造函数初始化继承的父类部分
//		//再初始化自己的成员
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		: Person(s)		//切片操作
//		, _id(s._id)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator= (const Student& s)
//	{
//		if (this != &s)
//		{
//			//如果不加域，会使得父类隐藏 -- 递归
//			Person::operator= (s);
//			_id = s._id;
//		}
//		return *this;
//	}
//
//	~Student()	//编译器认为子类的析构函数和父类的析构函数构成隐藏
//	{
//		//因此要添加域
//		//Person::~Person();
//		//清理自己的
//		cout << "~Student()" << endl;
//		//为了保证析构时，保持先子再父的后进先出的顺序析构
//		//子类的析构函数完成后，会自动去调用父类的析构函数
//	}
//private:
//	int _id;
//};
//int main()
//{
//	Student s("zhangsan", 1);
//	/*Student s1(s);
//	Student s3("helll", 2);
//	s = s3;*/
//}

//设计出一个类A， 让这个类不能被继承
// 只需要将基类的构造函数私有化
//class A
//{
//private:
//	A()
//	{}
//};
//
//class B : public A
//{
//public:
//	
//};
//
//int main()
//{
//	B b;
//}

//友元不能被继承，也就是说基类的友元不能访问子类私有和保护成员
//如果想访问，那么再增加一个友元
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//	//再一次友元
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}


//对于static对象，基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。无论派生出多少个子类，都只有一个static成员实例 。
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}

//多继承
//一个子类有两个或两个以上的直接父类
//有多继承就会出现菱形继承
//1.数据冗余
//2.二义性
//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
////cpp不能容忍数据冗余和二义性，
////提出了一个新方案：虚继承 virtual
////虚继承可以解决数据冗余和二义性 
///*
//	1.通过监视窗口已经看不到真实的存在，因为监视窗口被编译器处理过
//	2.建议使用内存窗口来进行查看
//*/
//
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	a._name = "peter";
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
//
//int main()
//{
//	Test();
//}

//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};

//继承的virtual会指向一个空间，第一个保存的是多态的偏移量 -- 虚基表
//第二个就是保存的虚继承的相对偏移量 -- 对于冗余的数据
/*
	D d;
	B b = d;
	C c = d;
	子类赋值给父类，这个切片行为就需要通过虚基表中的偏移量
	找到公共虚基类A的成员
*/
//虽然虚继承，补了菱形继承的坑，但是付出了很大的代价
/*
	1.对象模型更复杂了，学习理解成本很高
	2.付出了一定的效率，有一定的效率影响
*/

//实际中，一般情况下，建议不要设计出菱形继承
//那么就不会用菱形虚拟继承，就不会弄这么多复杂的了

//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.A::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//}

class A
{
public:
	void func()
	{}
protected:
	int _a;
};

//B继承了A，可以复用A
class B : public A
{
protected:
	int _b;
};

//C组合A，也可以复用A
class C
{
private:
	int _c;
	A _a;
};

//优先考虑组合，再考虑继承
//B和A之间是一种强关联关系 -- 白箱复用 -- 透明的 -- A的封装是对B是不太起作用的
//C和A之间是一种弱关联关系 -- 黑箱复用 -- 不可见的，只能用A公有的成员 - A的封装是对C起作用的
//软件设计类之间关系或者模块间关系强调，高内聚，低耦合
//类里面的成员之间关联度很高，类和类之间关联度很低

int main()
{

}