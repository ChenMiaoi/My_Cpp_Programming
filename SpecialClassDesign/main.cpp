#include <iostream>

using namespace std;

/*
	�����һ���ֻ࣬���ڶ��ϴ�������
		ʵ�ַ�ʽ��
		1. ����Ĺ��캯��˽�У���������������˽�С���ֹ���˵��ÿ�����ջ�����ɶ���
		2. �ṩһ����̬�ĳ�Ա�������ڸþ�̬��Ա��������ɶѶ���Ĵ���
*/
#if 0
class HeapOnly
{
public:
	static HeapOnly* CreatObj()	//��Ҫ����Ϊ��̬����Ȼû�ж����޷����ó�Ա����
	{
		return new HeapOnly;
	}
private:
	HeapOnly()	//����������Ϊ˽�У������˳������Ĵ���
	{}
	HeapOnly(const HeapOnly&);	//������������˽�У����Ҳ�ʵ�֣�����������ջ����������� -- ������C++98

	//C++11
	HeapOnly(const HeapOnly&) = delete;
};

int main()
{
	HeapOnly* p = HeapOnly::CreatObj();
	return 0;
}
#endif // !0 ����һ��ֻ���ڶ�����������

/*
	�����һ���ֻ࣬����ջ�ϴ�������
		����һ��ͬ�Ͻ����캯��˽�л���Ȼ����ƾ�̬�����������󷵻ؼ���
		������������new,��Ϊnew�ڵײ����void* operator new(size_t size)������ֻ�轫�ú������ε����ɡ�
			ע�⣺ҲҪ��ֹ��λnew
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
#endif // !0 ����һ��ֻ����ջ����������

/*
	�����һ���࣬���ܱ�����
		����ֻ����������������У��������캯���Լ���ֵ��������أ������Ҫ��һ�����ֹ������ֻ���ø���
		���ܵ��ÿ������캯���Լ���ֵ��������ؼ���
		C++98
			���������캯���븳ֵ���������ֻ���������壬���ҽ������Ȩ������Ϊ˽�м���
			ԭ��
				1. ���ó�˽�У����ֻ����û�����ó�private���û��Լ���������ⶨ���ˣ��Ϳ��Բ��ܽ�ֹ������
				2. ֻ���������壺����������Ϊ�ú�������������ã���������ʵҲû��ʲô���壬��д��������
					����������������˾Ͳ����ֹ��Ա�����ڲ�������
		C++11
			C++11��չdelete���÷���delete�����ͷ�new�������Դ�⣬�����Ĭ�ϳ�Ա���������=delete����
			ʾ�ñ�����ɾ������Ĭ�ϳ�Ա����
*/

/*
	�����һ���࣬���ܱ��̳�
		C++98
			�����캯��˽�л����������е���������Ĺ��캯�������޷��̳�
			����˽�г�Ա�����಻�ɼ�
		C++11
			����һ��final�ؼ��֣�ʹ��final�ؼ���
*/
#if 0
class Base final
{
private:
	Base()
	{}
};

//C++98��������ܱ��̳еķ�ʽ�������ף�ʵ�����ǿ��Լ̳У����Ƶ�������̳к���ʵ��������
class Child : public Base
{

};

int main()
{
	Child d;
}
#endif // !0 ���ܱ��̳е���


//����ģʽ  
/*
	1.��α�֤ȫ��(һ��������)ֻ��һ��Ψһʵ������
		a.���캯��˽�ж��壬��������͸�ֵ����������
		b.�ṩһ��GetInstance��ȡ��������

	����ģʽ���ṩһ����ֻ̬�뵥������ĳ�Աָ�룬��ʼ��ʱnewһ���������(����ʼ��mainִ��֮ǰ�ʹ����˵�������)
	����ģʽ��
*/

#if 0
//����ģʽ
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
	//ȫ��Ψһʵ������
	cout << Signleton::GetInstance() << endl;
	cout << Signleton::GetInstance() << endl;
	cout << Signleton::GetInstance() << endl;
}
#endif // !0 ����ģʽ

//����ģʽ
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
		//���赥�����й��캯����Ҫ���ܶ��ʼ�����������³��������ǳ���
	}

	Signleton(const Signleton&) = delete;
	Signleton& operator= (const Signleton&) = delete;

	static Signleton* _inst;
};

Signleton* Signleton::_inst = nullptr;

int main()
{
	//ȫ��Ψһʵ������
	cout << Signleton::GetInstance() << endl;
	cout << Signleton::GetInstance() << endl;
	cout << Signleton::GetInstance() << endl;
}