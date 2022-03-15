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

//模板参数
//类型模板参数
//非类型模板参数 -- 整形
template <class T = int, size_t N = 10>
class Array
{
public:
	void f()
	{
		N = 1000;	//大咩，报错desi
	}
private:
	T _a[N];
};

//非类型必须是整形
//template <double D>
//class B
//{
//private:
//
//};

//有时候，编译器默认函数模板或者类模板不能正确处理需要逻辑，需要针对一些情况进行特殊化处理，就要做模板的特化
//对指定的类型进行显示模板专有化
template <class T>
bool IsEqual(const T& left, const T& right)
{
	return left == right;
}

//对字符串要特殊化处理 -- 写一个函数模板的特殊化处理
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

//对T1， T2是int， int想做一些特殊化处理 -- 类模板特化
//特化的本质：显示指定实例化模板
template <>
class Date<int, int>
{
public:
	Date()
	{
		cout << "Date<int, int>" << endl;
	}
};

//偏特化
template <class T1>
class Date<T1, int>
{
public:
	Date()
	{
		cout << "Date<T1, int>" << endl;
	}
};

//偏特化，如果模板参数是指针，就进行下面的
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