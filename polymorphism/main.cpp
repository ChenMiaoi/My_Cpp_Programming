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

//������
//�������麯��������������� -- ����ʵ����������
//���Ը��õ�ȥ��ʾ��ʵ�����У�û��ʵ�������Ӧ�ĳ�������
//���ֽӿڼ̳У�ǿ������ȥ��д�麯��(����д����Ҳ�ǳ�����)
//class Car
//{
//public:
//	//���麯��
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
	�������̳в�һ���ģ�����֮�䶼����virtual�ؼ��֣�����ʹ�ó�����ȫ��һ�������������
	Ҳ�ǲ�һ���ģ�����֮��û�й���
	��̳в���������������������洢������̳е�ƫ����
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
//	�����̬�����Ժ󣬹��ɶ�̬��
//		ָ��������ã������麯��ʱ�����Ǳ���ʱȷ���ģ�������ʱ��ָ��Ķ����е����
//		��ȥ�Ҷ�Ӧ�麯�����ã�����ָ��ĸ�����󣬵��õľ��Ǹ�����麯����ָ����������
//		���󣬵��õľ���������麯��
//
//	��������ɶ�̬��
//		���Ǳ���ʱȷ����Ӧ�ĺ�������
//*/
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//}

//Ϊʲô����Ҫ���û�ָ�룿
//��Ϊ��Ƭ�������Ὣ���������й�ȥ�������û�ָ�����

//���̳�
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
////��ӡ���
//void PrintVFT(VFunc* ptr)	//�溯��ָ�������ָ�� -- VFunc ptr[]
//{
//	printf("����ַ : %p\n", ptr);
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

//��̳�
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
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%p,->", i, vTable[i]);
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