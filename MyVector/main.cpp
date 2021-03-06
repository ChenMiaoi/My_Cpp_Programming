#define _CRT_SECURE_NO_WARNINGS 1
#include "Vector.hpp"
#include <algorithm>
#include <string>

namespace mine
{
	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	template <class T>
	void Print(const vector<T>& v)
	{
		typename vector<T>::const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		Print(v);
	}

	void test3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		Print(v);

		v.resize(3);
		Print(v);

		v.resize(6);
		Print(v);

		v.resize(10);
		Print(v);
	}

	void test4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		Print(v);

		vector<int>::iterator pos = std::find(v.begin(), v.end(), 3);
		v.insert(pos, 30);
		Print(v);
		//迭代器失效问题
		//1. pos指向的位置的意义变了，pos不再指向3
		//2. pos野指针
		cout << *pos << endl;
		
	}

	void test5()
	{
		//删除所有的偶数
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);
		v.push_back(8);
		Print(v);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				it++;
			}
		}
		Print(v);
	}

	void test6()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		vector<int> v2;
		v2 = v1;
		Print(v1);
		Print(v2);
	}

	void test7()
	{
		vector<std::string> v1;
		v1.push_back("1111");
		v1.push_back("2222");
		v1.push_back("3333");
		v1.push_back("4444");
		v1.push_back("5555");
		Print(v1);

		for (const auto& e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}

int main()
{
	//mine::test1();
	//mine::test1();
	//mine::test3();
	//mine::test4();
	//mine::test5();
	//mine::test6();
	mine::test7();
	return 0;
}