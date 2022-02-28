#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void Print(const vector<T>& v)
{
	typename vector<T>::const_iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	v1.insert(v1.begin(), 0);
	Print(v1);
	v1.erase(v1.begin());
	Print(v1);

	//��3��ǰ�����һ��30
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	if (pos != v1.end())
	{
		v1.insert(pos, 30);
	}
	Print(v1);

	//ɾ��3
	pos = find(v1.begin(), v1.end(), 3);
	v1.erase(pos);	
	//�������������ȷ��pos�ĵ�ַ
	

	//-->���ɾ����30��ԭ���ǵ�����ʧЧ
	//1.�ڴ˴���ʱ��pos ��������ˣ����������Ժ�pos������ָ��3������30�����µ�����ʧЧ
	//2.�ڴ˴��������������Ұָ�����⣬size��capacityһ��������ٲ������ݾ����ˣ��ɿռ䱻�ͷţ�������һ���¿ռ�
	//�ڴ˴���posʧЧ������������Ϊpos������ˣ�������Ϊinsert�����Ժ�posλ��ָ��Ŀռ��Ѿ��ͷţ�pos�Ѿ���Ұָ����
	
	
	Print(v1);
}

void test2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	
	//Ҫ��ɾ��v�����е�ż��
	//g++�������û�б������������ڵ�����ʧЧerase֮��it��������ˣ�����һЩԪ�ز��ᱻ���
	//���������erase֮�����ݣ�����Ұָ��
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			//erase֮��itʧЧ������++��
			//����erase�᷵��ɾ��λ��it����һ��λ��
			it = v.erase(it);	//�������
		}
		else
		{
			++it;
		}
		//VS�£�������g++��Ӧ������������ᱨ����Ϊeraseɾ��it��itʧЧ֮��VS��it++֮������˼��
	}

	Print(v);
}

void test3()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);

	//C++98��Ӧ��������е�swap�����۷ǳ��󣬻�������
	//swap(v1, v2);
	v1.swap(v2);
}

//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}


//�������
void test()
{
	vector<vector<int>> vv;
	vv.resize(50);

	for (size_t i = 0; i < vv.size(); i++)
	{
		vv[i].resize(i + 1);
	}

	for (size_t j = 0; j < vv.size(); j++)
	{
		vv[j][0] = vv[j][vv.size() - 1] = 1;
	}

	for (size_t k = 0; k < vv.size(); k++)
	{
		for (size_t l = 0; l < vv[k].size(); ++l)
		{
			if (vv[k][l] != 1)
			{
				vv[k][l] = vv[k - 1][l] + vv[k - 1][l - 1];
			}
		}
	}
}

int main()
{
	test();
}