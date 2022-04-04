#include "AVLTree.h"
#include <string>

void test1()
{
	int a[] = { 1,3,5,7,6,9,2,8,10 };
	AVLTree<int, int> t;
	for (auto e : a)
		t.Insert(make_pair(e, e));
	t.PrevOrder();
	cout << endl;
	t.InOrder();
	cout << endl;
	t.PostOrder();
}

void test2()
{
	int a[] = { 16,3,7,11,9,26,18,14,15 };
	int a1[] = { 4,5,6,1,3,5,15,7,16,14 };
	AVLTree<int, int> t;
	for (auto e : a)
		t.Insert(make_pair(e, e));
	t.InOrder();
	cout << endl;
	t[3] *= 10;
	t[4] *= 10;
	t[5] *= 10;
	t.InOrder();
}

void test3()
{
	AVLTree<string, string> dict;
	dict.Insert(make_pair("sort", "ÅÅÐò"));
	dict.Insert(make_pair("left", "×ó±ß"));
	dict["left"] = "×ó±ß+Ê£Óà";
	dict["string"] = "×Ö·û´®";
	dict.InOrder();
}
int main()
{
	//test1();
	//test2();
	test3();
} 