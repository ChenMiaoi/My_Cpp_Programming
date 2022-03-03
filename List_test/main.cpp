#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

template <class Con>
void Print(const Con& c)
{
	typename Con::const_iterator it = c.begin();
	while (it != c.end())
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

	//遍历方式1
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//遍历方式2
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	int a[] = { 16, 2, 77, 29 };
	list<int> lt1(a, a + 4);
	//原生指针可以当作天然的迭代器使用
	//其实vector/string的迭代器也是原生指针
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v(a, a + 4);
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
	//sort的底层使用的是快速排序，快速排序要求容器迭代器必须是随机迭代器
	//不支持随机访问，效率就很低
	lt.sort();
	//但是不建议用，效率太低
	
}

void test2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	Print(lt);

	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	lt.insert(pos, 30);
	Print(lt);

	//vector的insert会导致迭代器失效
	//但是list的insert不会导致迭代器失效
	//list的erase会导致迭代器失效，因为将pos位置的迭代器指向的数据删除了，典型的野指针问题
	cout << *pos << endl;
	lt.erase(pos);
	cout << *pos << endl;
	Print(lt);
}

void test3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	lt.remove(3);
	Print(lt);
	lt.remove(30);
	Print(lt);

	lt.push_back(6);
	lt.push_back(6);
	lt.push_back(6);
	lt.push_back(6);
	lt.push_back(6);
	lt.unique();//但是这个去重，只会考虑连续的重复元素
	//因此，这个去重配合排序使用达到真正去重
	//但是一般不建议使用链表的排序，效率不高而底层复杂 
	Print(lt);
}

int main()
{
	//test1();
	//test2();
	test3();
}