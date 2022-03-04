#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

namespace mine
{
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
			cout << *it << " ";
			//it++;  因为我们这时候还没有重载后置++，因此此处只能用前置
			//为什么必须要重载++，因为这是链表，他的迭代器需要重载之后才能跳过一个元素
			++it;
		}
		cout << endl;
	}

	void test2()
	{

	}
}

int main()
{
	//mine::test1();
	mine::test2();
}