#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

namespace mine
{
	void Print(const list<int>& lt)
	{
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())	//甚至连!=都是需要重载的
		{
			*it += 1;
			cout << *it << " ";
			//it++;  因为我们这时候还没有重载后置++，因此此处只能用前置
			//为什么必须要重载++，因为这是链表，他的迭代器需要重载之后才能跳过一个元素
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		Print(lt);
	}

	class Date
	{
	public:
		int _year = 0;
		int _month = 1;
		int _day = 1;
	};

	void test2()
	{
		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << *it << " ";
			//cout << (*it)._year << " " << (*it)._month << " " << (*it)._day << endl;
			cout << it->_year << " " << it->_month << " " << it->_day << endl;
			++it;
		}
		cout << endl;
	}

	void test3()
	{
		list<int> lt;
		
	}
}

int main()
{
	//mine::test1();
	//mine::test2();
	mine::test3();
	return 0;
}