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
	//����pair�Ĺ��캯��������һ�������������
	m.insert(pair<int, double>(1, 1.1));
	m.insert(pair<int, double>(5, 5.5));
	m.insert(pair<int, double>(2, 2.2));
	m.insert(pair<int, double>(2, 3.3));	//key��ͬ�ͻ����ʧ�ܣ�����keyֵ

	//���ú���ģ����룬�������
	//�ô��ǲ���Ҫ����pair�����ú���ģ���Լ����ݣ�����������Щ
	m.insert(make_pair(2, 2.2));

	for (map<int, double>::const_iterator it = m.begin(); it != m.end(); it++)
		//cout << (*it).first << " : " << (*it).second << endl;
		cout << it->first << " : " << it->second << endl;
	cout << endl;

	//�����Ŀ�в�չ�������ռ䣬�Ͷ�Ҫָ��std��д������Ƚϳ�
	//ͨ��typedef�������
	map<string, string> dict;
	dict.insert(make_pair("insert", "����"));
	dict.insert(make_pair("tree", "��"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("right", "Ȩ��"));
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
	dict.insert(DICT_KV("insert", "����"));
	dict.insert(DICT_KV("tree", "��"));
	dict.insert(DICT_KV("sort", "����"));
	dict.insert(DICT_KV("right", "Ȩ��"));
	dict.insert(DICT_KV("left", "���"));
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

	//�ٴ��޸�
	auto ret = dict.find("left");
	if (ret != dict.end())
	{
		//ret->second.insert(ret->second.size() - 1, "��ʣ��");
		//�ɶ��Ե��Ż�����
		string& str = ret->second;
		str.insert(str.size() - 1, "��ʣ��");
	}
	for (DICT_ITER it = dict.begin(); it != dict.end(); it++)
		cout << it->first << " : " << it->second << endl;
	cout << endl;
}

void test3()
{
	//1.ͳ�ƴ���, 2.�ҳ������ϲ��������ˮ��
	string arr[] = { "�㽶", "�㽶", "�㽶", "�㽶", "�㽶", "�㽶", "�㽶", 
					"ƻ��", "ƻ��", "ƻ��", "ƻ��", "ƻ��", 
					"��ݮ", "��ݮ", "��ݮ", "��ݮ",
					"����", "����", "����", 
					"ӣ��", "ӣ��" };
	map<string, int> countMap;
	//��ʽһ
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

	//��ʽ��
	//for (const auto& str : arr)
	//{
	//	/*pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(str, 1));*/
	//	//����insert�ķ���ֵ������
	//	//�Ȳ��룬���str�Ѿ���map�У���insert�᷵��str���ڽڵ�ĵ�����������++��������
	//	auto ret = countMap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//		ret.first->second++;
	//}

	//��ʽ��
	for (const auto& str : arr)
	{
		countMap[str]++;
		/*
			���k����map�У��Ȳ���<k, V()>��Ȼ�󷵻ؽڵ���V���������
			���k�Ѿ���map�У�����k���ڽڵ��ӦV���������
			�൱�ڣ�
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

	//����[]��һЩ��չѧϰ
	map<string, string> dict;
	dict["left"] = "���";	//�Ȳ���key�����޸�value

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
	//1.ͳ�ƴ���, 2.�ҳ������ϲ��������ˮ��
	string arr[] = { "�㽶", "�㽶", "�㽶", "�㽶", "�㽶", "�㽶", "�㽶",
					"ƻ��", "ƻ��", "ƻ��", "ƻ��", "ƻ��",
					"��ݮ", "��ݮ", "��ݮ", "��ݮ",
					"����", "����", "����",
					"ӣ��", "ӣ��" };
	map<string, int> countMap;
	for (const auto& str : arr)
		countMap[str]++;
	for (const auto& e : countMap)
		cout << e.first << " : " << e.second << endl;

	//������ˮ�����������˼·
	//����vector����
	//vector<pair<string, int>> v;
	vector<map<string, int>::iterator> v;
	for (map<string, int>::iterator countMapIt = countMap.begin(); countMapIt != countMap.end(); countMapIt++)
		v.push_back(countMapIt);
	sort(v.begin(), v.end(), MapItCmp());

	//����map���� -- ����pair����
	map<int, string, greater<int>> sortMap;
	for (auto e : countMap)
		sortMap.insert(make_pair(e.second, e.first));
	for (const auto& e : sortMap)
		cout << e.second << " : " << e.first << endl;

	//����set���� -- ������pair����
	set<map<string, int>::iterator, MapItCmp> sortSet;
	for (map<string, int>::iterator countMapIt = countMap.begin(); countMapIt != countMap.end(); countMapIt++)
		sortSet.insert(countMapIt);
	for (const auto& e : sortSet)
		cout << (*e).first << " : " << (*e).second << endl;

	//����priority_queue����
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
	//��һ�����������ֵ����
	//�ڶ�������multimap���ṩ[]����
	map<string, string> dict;
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("left", "ʣ��"));

	multimap<string, string> mdict;
	mdict.insert(make_pair("left", "���"));
	mdict.insert(make_pair("left", "ʣ��"));

}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
}