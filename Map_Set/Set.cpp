#include <iostream>
#include <set>
#include <string>

using namespace std;

void test1()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(3);
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(9);

	//1.排序+去重 -- set不能修改已经插入的值，不能随意的更改KEY
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (const auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	for (set<int>::reverse_iterator rit = s.rbegin(); rit != s.rend(); rit++)
	{
		cout << *rit << " ";
	}
	cout << endl;

	//2.检查单词拼写是否正确
	//思路：将词库中的单词都放进set对象中，把每个写出来的单词去查一下
	//set中在不在，在就是正确的，不在就是错误的
	set<string> strSet;
	strSet.insert("sort");
	strSet.insert("right");
	strSet.insert("left");
	strSet.insert("insert");

	for (set<string>::const_iterator sit = strSet.begin(); sit != strSet.end(); sit++)
	{
		cout << *sit << " ";
	}
	cout << endl;

	for (const auto& e : strSet)
		cout << e << " ";
	cout << endl;

	set<string>::iterator ret = strSet.find("tree");
	if (ret != strSet.end())
	{
		cout << "It is right" << endl;
	}
	else
	{
		cout << "It is wrong" << endl;
	}
}

void test2()
{
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(3);
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(9);
	//先查找，找到了再删。
	//如果没找到删除就会报错
	auto pos = s.find(4);
	s.erase(pos);
	s.erase(3);
	//s.erase(30);
	pos = s.find(30);
	if (pos != s.end())
		s.erase(pos);

	for (auto e : s)
		cout << e << " ";
	cout << endl;
}

void test3()
{
	//multiset允许键值冗余，使用方法基本跟set一致
	multiset<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(3);
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(9);
	s.insert(3);

	//可以容纳重复元素
	for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;

	//当find查找的value有多个的时候，那么他找的是中序的第一个
	auto pos = s.find(3);
	while (*pos == 3)
	{
		cout << *pos << endl;
		++pos;
	}
	cout << s.count(3) << endl;

	//multiset的erase会将给出的键值所有删除
	s.erase(3);
	for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
}
