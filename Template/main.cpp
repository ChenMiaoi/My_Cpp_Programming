#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

//void test_deque()
//{
//	deque<int> dq;
//	dq.push_back(1);
//	dq.push_back(2);
//	dq.push_back(3);
//	dq.push_back(4);
//	dq.push_front(5);
//	dq.push_front(6);
//	dq.push_front(7);
//	dq.push_front(8);
//
//	for (size_t i = 0; i < dq.size(); i++)
//	{
//		cout << dq[i] << " ";
//	}
//	cout << endl;
//
//	deque<int>::iterator it = dq.begin();
//	while (it != dq.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	 
//	for (auto e : dq)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//#define N 100

//ģ�����
//����ģ�����
//������ģ����� -- ����
template <class T = int, size_t N = 10>
class Array
{
public:
	void f()
	{
		N = 1000;	//���㣬����desi
	}
private:
	T _a[N];
};

//�����ͱ���������
//template <double D>
//class B
//{
//private:
//
//};

//��ʱ�򣬱�����Ĭ�Ϻ���ģ�������ģ�岻����ȷ������Ҫ�߼�����Ҫ���һЩ����������⻯������Ҫ��ģ����ػ�
//��ָ�������ͽ�����ʾģ��ר�л�
template <class T>
bool IsEqual(const T& left, const T& right)
{
	return left == right;
}

//���ַ���Ҫ���⻯���� -- дһ������ģ������⻯����
template <>
bool IsEqual<char*>(char* const& left, char* const& right)
{
	return strcmp(left, right) == 0;
}

bool IsEqual(char* left, char* right)
{
	return strcmp(left, right) == 0;
}

template <class T1, class T2>
class Date
{
public:
	Date()
	{
		cout << "Date<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//��T1�� T2��int�� int����һЩ���⻯���� -- ��ģ���ػ�
//�ػ��ı��ʣ���ʾָ��ʵ����ģ��
template <>
class Date<int, int>
{
public:
	Date()
	{
		cout << "Date<int, int>" << endl;
	}
};

//ƫ�ػ�
template <class T1>
class Date<T1, int>
{
public:
	Date()
	{
		cout << "Date<T1, int>" << endl;
	}
};

//ƫ�ػ������ģ�������ָ�룬�ͽ��������
template <class T1, class T2>
class Date<T1*, T2*>
{
public:
	Date()
	{
		cout << "Date<T1*, T2*>" << endl;
	}
};

template <class T1, class T2>
class Date<T1&, T2&>
{
public:
	Date()
	{
		cout << "Date<T1&, T2&>" << endl;
	}
};

template <class T1, class T2>
class Date<T1&, T2*>
{
public:
	Date()
	{
		cout << "Date<T1&, T2*>" << endl;
	}
};

int main()
{
	Date<int, int> d1;
	Date<int, double> d2; 
	Date<char, int> d3;
	Date<double*, int*> d4;
	Date<int*, int*> d5;
	Date<int&, int&> d6;
	Date<double&, int&> d7;
	Date<double&, int*> d8;
	return 0;
}