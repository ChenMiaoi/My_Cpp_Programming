#include <iostream>

using namespace std;

/*
	��̬ -- ������̬
	��̬�Ķ�̬ -- ��������
	��̬�Ķ�̬ -- ����ָ������õ�����д�麯��
	1. ����ָ���������ָ���࣬���õľ��Ǹ�����麯��
	2. ����ָ���������ָ����һ�����࣬���õľ���������麯�� 
		��ͬ�����Ͷ���ȥ���ͬһ�����飬�����Ķ����ǲ�һ���ģ����Ҳ�ǲ�һ����

	������(ȱһ����)
	1. ����ͨ�������ָ��������õ����麯��
	2. �����õĺ����������麯���������麯��Ҫ�������
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

//ע�⣺
/*
	1.ֻ����ķǾ�̬��Ա�����������麯��
	2.�麯������virtual����̳��е�virtual��ͬһ���ؼ��֣���������֮��û���κι�ϵ
		�麯����Ϊ��ʵ�ֶ�̬
		��̳���Ϊ�˽�����μ̳е���������Ͷ�����
*/

/*
	�麯������д��
		����������һ����������ȫ��ͬ���麯��(���������麯��������麯���ķ���ֵ��
�͡��������֡������б���ȫ��ͬ)����������麯����д�˻�����麯����
*/
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ ȫ��" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊ ���" << endl;
//	}
//};
//
//class Soldier : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "���� ��Ʊ" << endl;
//	}
//};
//
//void f(Person& p)
//{
//	//����ͬ���͵Ķ��󣬵��õ��ǲ�ͬ�ĺ�����ʵ���˵��õĶ�����̬
//	p.BuyTicket();
//}
//
//void f(Person* p)
//{
//	p->BuyTicket();
//}

//int main()
//{
//	Person p;	//��ͨ��
//	Student s;	//ѧ��
//	Soldier so;	//����
//	
//	f(p);
//	f(s);
//	f(so);
//	cout << endl;
//	f(&p);
//	f(&s);
//	f(&so);
//}

//�麯����д�����⣺
//1. Э�� -- �������������麯������ֵ���Ͳ�ͬ -- �ҷ���ֵ�Ǹ��ӹ�ϵ��ָ�������
//���Ǳ����ǻ��෵�ػ���ָ������ã������෵��������ָ�������
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

//2.����������д
//class Person
//{
//public:
//	//����Ѹ���������������Ϊ�麯��������������麯��������д�����麯��
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
//		//student��person���������ĺ���������������ͬ���������ǹ����麯����д
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	//����ͨ�����£�����������������Ƿ񹹳���д������Ҫ��û��Ӱ��
//	/*Person p;
//	Student s;*/
//
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	//���û������������ô�����p2ָ����������Ӧ�õ�����������������û�е��ã������ڴ�й¶
//	delete p1;
//	delete p2;
//	//ֻ������������д�ˣ���ô����delete����ָ�룬������������������ʵ�ֶ�̬
//	//ָ���࣬���ø�����������
//	//ָ�����࣬����������������
//	//����ʵ����ȷ����
//}


//final�ؼ��֣����û�����麯������д
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};
//
//int main()
//{
//	
//}

//override ���������麯���Ƿ������д
//class Car {
//public:
//	virtual void Drive() {}
//};
//
//class Benz :public Car {
//public:
//	virtual void Drive(int i) override { cout << "Benz-����" << endl; }
//};
//
//int main()
//{
//
//}

