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
		dict.Insert("string", "字符串");
		dict.Insert("tree", "树");
		dict.Insert("left", "左边、剩余");
		dict.Insert("right", "右边、权力");
		dict.Insert("sort", "排序");
		//...插入词库中的单词
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret == nullptr)
			{
				cout << "单词拼写错误，词库中没有这个单词: " << str << endl;
			}
			else
			{
				cout << ret->_key << "中文翻译:> " << ret->_value << endl;
			}
		}
	}

	void test2()
	{
		//统计水果出现的次数
		string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果" };
		BSTree<string, int> countTree;
		for (const auto& str : arr)
		{
			//先查找水果在不在搜索树中
			// 1.不在，说明水果第一次出现，则插入<水果，1>
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