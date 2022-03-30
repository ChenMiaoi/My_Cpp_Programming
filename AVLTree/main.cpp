#include "AVLTree.h"

void test1()
{
	int a[] = { 1,3,5,7,6 };
	AVLTree<int, int> t;
	for (auto e : a)
		t.Insert(make_pair(e, e));
}

int main()
{
	test1();
} 