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

	//在3的前面插入一个30
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	if (pos != v1.end())
	{
		v1.insert(pos, 30);
	}
	Print(v1);

	//删除3
	pos = find(v1.begin(), v1.end(), 3);
	v1.erase(pos);	
	//解决方案，重新确立pos的地址
	

	//-->结果删除了30，原因是迭代器失效
	//1.在此处的时候，pos 的意义变了，插入数据以后，pos不再是指向3，而是30，导致迭代器失效
	//2.在此处还会崩溃，出现野指针问题，size和capacity一样，如果再插入数据就满了，旧空间被释放，开辟了一块新空间
	//在此处的pos失效并不仅仅是因为pos意义变了，而是因为insert增容以后，pos位置指向的空间已经释放，pos已经是野指针了
	
	
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
	
	//要求删除v中所有的偶数
	//g++下面可能没有崩溃，但是由于迭代器失效erase之后，it的意义变了，导致一些元素不会被检查
	//极端情况，erase之后缩容，导致野指针
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			//erase之后，it失效，不能++，
			//但是erase会返回删除位置it的下一个位置
			it = v.erase(it);	//解决方案
		}
		else
		{
			++it;
		}
		//VS下，不论是g++对应的哪种情况都会报错，因为erase删除it，it失效之后，VS在it++之后进行了检查
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

	//C++98中应当避免库中的swap，代价非常大，会进行深拷贝
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


//杨辉三角
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