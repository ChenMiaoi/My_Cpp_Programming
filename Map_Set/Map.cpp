#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

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

	//如果项目中不展开命名空间，就都要指定std，写起来会比较长
	//通过typedef简短命名
	map<string, string> dict;
	dict.insert(make_pair("insert", "插入"));
	dict.insert(make_pair("tree", "树"));
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("right", "权力"));
	for (map<string, string>::const_iterator it = dict.begin(); it != dict.end(); it++)
		cout << it->first << " : " << it->second << endl;
	cout << endl;
}

void test2()
{
	typedef std::map<std::string, std::string> DICT;
	typedef std::pair<std::string, std::string> DICT_KV;
	typedef std::map<std::string, std::string>::iterator DICT_ITER;
	DICT dict;
	dict.insert(DICT_KV("insert", "插入"));
	dict.insert(DICT_KV("tree", "树"));
	dict.insert(DICT_KV("sort", "排序"));
	dict.insert(DICT_KV("right", "权力"));
	dict.insert(DICT_KV("left", "左边"));
	DICT_ITER dit = dict.begin();
	while (dit != dict.end())
	{
		dit->second.insert(0, "{");
		dit->second += "}";
		++dit;
	}

	for (DICT_ITER it = dict.begin(); it != dict.end(); it++)
		cout << it->first << " : " << it->second << endl;
	cout << endl;

	//再次修改
	auto ret = dict.find("left");
	if (ret != dict.end())
	{
		//ret->second.insert(ret->second.size() - 1, "、剩余");
		//可读性的优化技巧
		string& str = ret->second;
		str.insert(str.size() - 1, "、剩余");
	}
	for (DICT_ITER it = dict.begin(); it != dict.end(); it++)
		cout << it->first << " : " << it->second << endl;
	cout << endl;
}

void test3()
{
	//1.统计次数, 2.找出大家最喜欢的三种水果
	string arr[] = { "香蕉", "香蕉", "香蕉", "香蕉", "香蕉", "香蕉", "香蕉", 
					"苹果", "苹果", "苹果", "苹果", "苹果", 
					"草莓", "草莓", "草莓", "草莓",
					"榴莲", "榴莲", "榴莲", 
					"樱桃", "樱桃" };
	map<string, int> countMap;
	//方式一
	/*for (const auto& str : arr)
	{
		map<string, int>::iterator ret = countMap.find(str);
		if (ret != countMap.end())
		{
			ret->second++;
		}
		else
		{
			countMap.insert(make_pair(str, 1));
		}
	}*/

	//方式二
	//for (const auto& str : arr)
	//{
	//	/*pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(str, 1));*/
	//	//关于insert的返回值的巧用
	//	//先插入，如果str已经在map中，则insert会返回str所在节点的迭代器，我们++次数即可
	//	auto ret = countMap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//		ret.first->second++;
	//}

	//方式三
	for (const auto& str : arr)
	{
		countMap[str]++;
		/*
			如果k不在map中，先插入<k, V()>，然后返回节点中V对象的引用
			如果k已经在map中，返回k所在节点对应V对象的引用
			相当于：
			mapped_type = Value -- the second template
			mapped_type& operator[] (const Key& key)
				return (*((this->insert(make_pair(key, mapped_type()))).first)).second;
				1.make_pair(key, mapped_type())
				2.this->insert(make_pair())
				3.this->insert(make_pair()).first -- pair<iterator, bool>.first = iterator
				4.(*this->insert(make_pair()).first).second
					--(pair<iterator, bool>.first).second = iterator.second = value
		*/
	}

	//关于[]的一些扩展学习
	map<string, string> dict;
	dict["left"] = "左边";	//先插入key，再修改value

	for (const auto& e : countMap)
	{
		cout << e.first << " : " << e.second << endl;
	}
}

struct MapItCmp
{
	bool operator ()(map<string, int>::iterator x, map<string, int>::iterator y) const
	{return x->second > y->second;}
};

void test4()
{
	//1.统计次数, 2.找出大家最喜欢的三种水果
	string arr[] = { "香蕉", "香蕉", "香蕉", "香蕉", "香蕉", "香蕉", "香蕉",
					"苹果", "苹果", "苹果", "苹果", "苹果",
					"草莓", "草莓", "草莓", "草莓",
					"榴莲", "榴莲", "榴莲",
					"樱桃", "樱桃" };
	map<string, int> countMap;
	for (const auto& str : arr)
		countMap[str]++;
	for (const auto& e : countMap)
		cout << e.first << " : " << e.second << endl;

	//对所有水果次数排序的思路
	//利用vector排序
	//vector<pair<string, int>> v;
	vector<map<string, int>::iterator> v;
	for (map<string, int>::iterator countMapIt = countMap.begin(); countMapIt != countMap.end(); countMapIt++)
		v.push_back(countMapIt);
	sort(v.begin(), v.end(), MapItCmp());

	//利用map排序 -- 拷贝pair数据
	map<int, string, greater<int>> sortMap;
	for (auto e : countMap)
		sortMap.insert(make_pair(e.second, e.first));
	for (const auto& e : sortMap)
		cout << e.second << " : " << e.first << endl;

	//利用set排序 -- 不拷贝pair数据
	set<map<string, int>::iterator, MapItCmp> sortSet;
	for (map<string, int>::iterator countMapIt = countMap.begin(); countMapIt != countMap.end(); countMapIt++)
		sortSet.insert(countMapIt);
	for (const auto& e : sortSet)
		cout << (*e).first << " : " << (*e).second << endl;

	//利用priority_queue排序
	cout << endl;
	typedef map<string, int>::iterator M_IT;
	priority_queue<M_IT, vector<M_IT>, MapItCmp> pq;
	for (M_IT countMapIt = countMap.begin(); countMapIt != countMap.end(); countMapIt++)
		pq.push(countMapIt);
	while (!pq.empty())
	{
		cout << (pq.top())->first << " : " << (pq.top())->second << endl;
		pq.pop();
	}

	/*size_t size = pq.size();
	for (size_t i = 0; i < size; i++) {
		cout << (pq.top())->first << " : " << (pq.top())->second << endl;
		pq.pop();
	}*/
}

void test5()
{
	//第一个区别，允许键值冗余
	//第二个区别，multimap不提供[]重载
	map<string, string> dict;
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("left", "剩余"));

	multimap<string, string> mdict;
	mdict.insert(make_pair("left", "左边"));
	mdict.insert(make_pair("left", "剩余"));

}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
}