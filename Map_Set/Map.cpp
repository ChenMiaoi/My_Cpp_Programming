#include <iostream>
#include <string>
#include <map>

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
}

int main()
{
	test1();
}