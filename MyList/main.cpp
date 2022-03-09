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
		while (it != lt.end())	//������!=������Ҫ���ص�
		{
			*it += 1;
			cout << *it << " ";
			//it++;  ��Ϊ������ʱ��û�����غ���++����˴˴�ֻ����ǰ��
			//Ϊʲô����Ҫ����++����Ϊ�����������ĵ�������Ҫ����֮���������һ��Ԫ��
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