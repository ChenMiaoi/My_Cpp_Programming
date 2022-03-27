#include "BSTree.hpp"
#include <string>

namespace K
{
	void test1()
	{
		BSTree<int> t;
		int a[] = { 5,3,4,1,7,8,6,0,2,9 };
		for (auto e : a)
			t.Insert(e);
		t.InOrder();
		for (auto e : a)
		{
			t.Erase(e);
			t.InOrder();
		}
	}

	void test2()
	{
		BSTree<int> t;
		int a[] = { 5,3,4,1,7,8,6,0,2,9 };
		for (auto e : a)
			t.Insert(e);
		t.InOrder();
		BSTree<int> t1(t);
		t1.InOrder();

		BSTree<int> t2;
		t2 = t1;
		t2.InOrder();
	}
}

namespace KV
{
	void test1()
	{
		BSTree<string, string> dict;
		dict.Insert("string", "�ַ���");
		dict.Insert("tree", "��");
		dict.Insert("left", "��ߡ�ʣ��");
		dict.Insert("right", "�ұߡ�Ȩ��");
		dict.Insert("sort", "����");
		//...����ʿ��еĵ���
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret == nullptr)
			{
				cout << "����ƴд���󣬴ʿ���û���������: " << str << endl;
			}
			else
			{
				cout << ret->_key << "���ķ���:> " << ret->_value << endl;
			}
		}
	}

	void test2()
	{
		//ͳ��ˮ�����ֵĴ���
		string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��" };
		BSTree<string, int> countTree;
		for (const auto& str : arr)
		{
			//�Ȳ���ˮ���ڲ�����������
			// 1.���ڣ�˵��ˮ����һ�γ��֣������<ˮ����1>
			//BSTreeNode<string, int>* ret = conutTree.Find(str);
			auto ret = countTree.Find(str);
			if (ret == nullptr)
				countTree.Insert(str, 1);
			else
				ret->_value++;
		}
		countTree.InOrder();
	}
}

int main()
{
	//K::test1();
	//KV::test1();
	KV::test2();
}