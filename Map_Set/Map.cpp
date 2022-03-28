#include <iostream>
#include <string>
#include <map>

using namespace std;

void test1()
{
	map<int, double> m;
	//调用pair的构造函数，构造一个匿名对象插入
	m.insert(pair<int, double>(1, 1.1));
	m.insert(pair<int, double>(5, 5.5));
	m.insert(pair<int, double>(2, 2.2));
	m.insert(pair<int, double>(2, 3.3));	//key相同就会插入失败，检索key值

	//调用函数模板插入，构造对象
	//好处是不需要声明pair参数让函数模板自己推演，用起来方便些
	m.insert(make_pair(2, 2.2));

	for (map<int, double>::const_iterator it = m.begin(); it != m.end(); it++)
		//cout << (*it).first << " : " << (*it).second << endl;
		cout << it->first << " : " << it->second << endl;
	cout << endl;
}

int main()
{
	test1();
}