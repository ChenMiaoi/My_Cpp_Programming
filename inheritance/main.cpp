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

//�̳�Ȩ����Զֻ����С�ļ̳�
// public > projected > private

//�����˽�г�Ա�̳��������ɼ�����˼�ǣ�
//�ڴ��ϣ���������������Ա�������﷨�涨�����ǲ���ȥ����

//int main()
//{
//	Stu s;
//	s.Print();
//
//	Teacher t;
//	t.Print();
//	return 0;
//}

//��ֵ���ݹ��� -- ��Ƭ
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
//	//������Ը�ֵ�����࣬���಻���Ը�ֵ������
//	//���������Ĺ��̣�������Ƭ����(�����)
//	/*p = s;
//	s = p;*/
//
//	Person* ptr = &s;
//	Person& ref = s;
//}

//�����Ա���θ����ͬ����Ա��ֱ�ӷ��ʣ���������������أ�Ҳ�����ض���
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
//	~Person()	//��Ϊ -> �����̬��һЩԭ���κ����������������ᱻͳһ�����destructor
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int id)
//		: Person(name)
//		, _id(id)
//	{
//		//���ø��๹�캯����ʼ���̳еĸ��ಿ��
//		//�ٳ�ʼ���Լ��ĳ�Ա
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		: Person(s)		//��Ƭ����
//		, _id(s._id)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator= (const Student& s)
//	{
//		if (this != &s)
//		{
//			//��������򣬻�ʹ�ø������� -- �ݹ�
//			Person::operator= (s);
//			_id = s._id;
//		}
//		return *this;
//	}
//
//	~Student()	//��������Ϊ��������������͸��������������������
//	{
//		//���Ҫ�����
//		//Person::~Person();
//		//�����Լ���
//		cout << "~Student()" << endl;
//		//Ϊ�˱�֤����ʱ�����������ٸ��ĺ���ȳ���˳������
//		//���������������ɺ󣬻��Զ�ȥ���ø������������
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

//��Ƴ�һ����A�� ������಻�ܱ��̳�
// ֻ��Ҫ������Ĺ��캯��˽�л�
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

//��Ԫ���ܱ��̳У�Ҳ����˵�������Ԫ���ܷ�������˽�кͱ�����Ա
//�������ʣ���ô������һ����Ԫ
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//	//��һ����Ԫ
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}


//����static���󣬻��ඨ����static��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա���������������ٸ����࣬��ֻ��һ��static��Աʵ�� ��
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//}

//��̳�
//һ���������������������ϵ�ֱ�Ӹ���
//�ж�̳оͻ�������μ̳�
//1.��������
//2.������
//class Person
//{
//public:
//	string _name; // ����
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
////cpp����������������Ͷ����ԣ�
////�����һ���·�������̳� virtual
////��̳п��Խ����������Ͷ����� 
///*
//	1.ͨ�����Ӵ����Ѿ���������ʵ�Ĵ��ڣ���Ϊ���Ӵ��ڱ������������
//	2.����ʹ���ڴ洰�������в鿴
//*/
//
//void Test()
//{
//	// �������ж������޷���ȷ֪�����ʵ�����һ��
//	Assistant a;
//	a._name = "peter";
//	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
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

//�̳е�virtual��ָ��һ���ռ䣬��һ��������Ƕ�̬��ƫ���� -- �����
//�ڶ������Ǳ������̳е����ƫ���� -- �������������
/*
	D d;
	B b = d;
	C c = d;
	���ำֵ�����࣬�����Ƭ��Ϊ����Ҫͨ��������е�ƫ����
	�ҵ����������A�ĳ�Ա
*/
//��Ȼ��̳У��������μ̳еĿӣ����Ǹ����˺ܴ�Ĵ���
/*
	1.����ģ�͸������ˣ�ѧϰ���ɱ��ܸ�
	2.������һ����Ч�ʣ���һ����Ч��Ӱ��
*/

//ʵ���У�һ������£����鲻Ҫ��Ƴ����μ̳�
//��ô�Ͳ�������������̳У��Ͳ���Ū��ô�ิ�ӵ���

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

//B�̳���A�����Ը���A
class B : public A
{
protected:
	int _b;
};

//C���A��Ҳ���Ը���A
class C
{
private:
	int _c;
	A _a;
};

//���ȿ�����ϣ��ٿ��Ǽ̳�
//B��A֮����һ��ǿ������ϵ -- ���临�� -- ͸���� -- A�ķ�װ�Ƕ�B�ǲ�̫�����õ�
//C��A֮����һ����������ϵ -- ���临�� -- ���ɼ��ģ�ֻ����A���еĳ�Ա - A�ķ�װ�Ƕ�C�����õ�
//��������֮���ϵ����ģ����ϵǿ�������ھۣ������
//������ĳ�Ա֮������Ⱥܸߣ������֮������Ⱥܵ�

int main()
{

}