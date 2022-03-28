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

	//1.����+ȥ�� -- set�����޸��Ѿ������ֵ����������ĸ���KEY
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

	//2.��鵥��ƴд�Ƿ���ȷ
	//˼·�����ʿ��еĵ��ʶ��Ž�set�����У���ÿ��д�����ĵ���ȥ��һ��
	//set���ڲ��ڣ��ھ�����ȷ�ģ����ھ��Ǵ����
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
	//�Ȳ��ң��ҵ�����ɾ��
	//���û�ҵ�ɾ���ͻᱨ��
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
	//multiset�����ֵ���࣬ʹ�÷���������setһ��
	multiset<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(3);
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(9);
	s.insert(3);

	//���������ظ�Ԫ��
	for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	cout << endl;

	//��find���ҵ�value�ж����ʱ����ô���ҵ�������ĵ�һ��
	auto pos = s.find(3);
	while (*pos == 3)
	{
		cout << *pos << endl;
		++pos;
	}
	cout << s.count(3) << endl;

	//multiset��erase�Ὣ�����ļ�ֵ����ɾ��
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
