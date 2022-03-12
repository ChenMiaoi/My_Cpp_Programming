#pragma once

#include <iostream>
#include <vector>
#include <deque>

using std::cout;
using std::endl;
using std::cin;

namespace mine_stack
{
	template <class T, class Container = std::deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		T top()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}