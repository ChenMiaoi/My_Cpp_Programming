#include "BSTree.hpp"

void test1()
{
	BSTree<int> t;
	int a[] = { 5,3,4,1,7,8,6,0,2,9 };
	for (auto e : a)
		t.Insert(e);
	t.PrevOrder();
	t.Erase(7);
	t.PrevOrder();
	for (auto e : a)
		t.Erase(e);
	t.PostOrder();
}

int main()
{
	test1();
}