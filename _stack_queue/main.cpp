#include "Stack.h"
#include "Queue.h"
#include "Priority_queue.h"
#include <list>
#include <vector>
#include <queue>
#include <functional>

namespace mine_stack
{
	void test1()
	{
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}

namespace mine_queue
{
	void test1()
	{
		//queue<int, vector<>> 就会报错 
		queue<int, std::list<int>> q;
		q.push(1);
		q.push(2);
		q.push(3); 
		q.push(4);
		q.push(5);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}

void priority_queue()
{
	//默认是一个大堆，默认大的优先级高 
	//std::priority_queue<int> pq;

	//变成小堆，小的优先级高
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	pq.push(3);
	pq.push(5);
	pq.push(2);
	pq.push(1);
	pq.push(6);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

namespace mine_priority_queue
{
	void test1()
	{
		//priority_queue<int> pq;

		priority_queue<int, std::vector<int>, greater<int>> pq;
		pq.push(3);
		pq.push(5);
		pq.push(2);
		pq.push(1);
		pq.push(6);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}

//仿函数 -- 函数对象， 这个类的对象可以像函数一样使用
struct LessInt
{
	bool operator() (int x, int y)
	{
		return x < y;
	}
};

template <class T>
struct Less
{
	bool operator() (const T& x, const T& y)
	{
		return x < y;
	}
};

int main()
{
	//mine_stack::test1();
	//mine_queue::test1();
	//priority_queue();
	mine_priority_queue::test1();
}