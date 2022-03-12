#include "Stack.h"

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

int main()
{
	mine_stack::test1();
}