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

	//������ʽ1
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//������ʽ2
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	int a[] = { 16, 2, 77, 29 };
	list<int> lt1(a, a + 4);
	//ԭ��ָ����Ե�����Ȼ�ĵ�����ʹ��
	//��ʵvector/string�ĵ�����Ҳ��ԭ��ָ��
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v(a, a + 4);
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
	//sort�ĵײ�ʹ�õ��ǿ������򣬿�������Ҫ���������������������������
	//��֧��������ʣ�Ч�ʾͺܵ�
	lt.sort();
	//���ǲ������ã�Ч��̫��
	
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

	//vector��insert�ᵼ�µ�����ʧЧ
	//����list��insert���ᵼ�µ�����ʧЧ
	//list��erase�ᵼ�µ�����ʧЧ����Ϊ��posλ�õĵ�����ָ�������ɾ���ˣ����͵�Ұָ������
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
	lt.unique();//�������ȥ�أ�ֻ�ῼ���������ظ�Ԫ��
	//��ˣ����ȥ���������ʹ�ôﵽ����ȥ��
	//����һ�㲻����ʹ�����������Ч�ʲ��߶��ײ㸴�� 
	Print(lt);
}

int main()
{
	//test1();
	//test2();
	test3();
}