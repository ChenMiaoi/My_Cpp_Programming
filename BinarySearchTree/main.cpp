#include "BSTree.hpp"

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

int main()
{
	//test1();
	test2();
}