#pragma once
#include <iostream>
#include <vector>

namespace mine_priority_queue
{
	template <class T>
	struct less
	{
		bool operator() (const T& x, const T& y)
		{
			return x < y;
		}
	};

	template <class T>
	struct greater
	{
		bool operator() (const T& x, const T& y)
		{
			return x > y;
		}
	};

	template <class T, class Container = std::vector<T>, class Compare = less<typename Container::value_type>>	//在实例化之前，编译器无法知道这个类，因此要加上typename，这个typename告诉编译器这是一个类型名称，等它实例化之后再去它中找到对象
	class priority_queue
	{
	public: 
		void AdjustUp(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] < _con[parent])
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void AdjustDown(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				//if (child + 1 < _con.size() && _con[child] > _con[child + 1])
				if (com(child + 1, _con.size()) && com(_con[child], _con[child + 1]))
				{
					++child;
				}

				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);

			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			AdjustDown(0);
		}

		T top()
		{
			return _con[0];
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