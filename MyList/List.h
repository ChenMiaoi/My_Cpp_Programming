#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

namespace mine
{
	template <class T>
	struct _list_node
	{
		T _val;
		_list_node<T>* _next;
		_list_node<T>* _prev;

		_list_node(const T& val = T())
			: _val(val)
			, _prev(nullptr)
			, _next(nullptr)
		{}
	};

	template <class T>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T> self;

		node* _pnode;
		_list_iterator(node* pnode)
			: _pnode(pnode)
		{}

		//节点的指针原生行为不满足迭代器定义
		//这里迭代器通过类去封装节点的指针，重载运算符来控制
		T operator* ()
		{
			return _pnode->_val;
		}

		bool operator!= (const self& s)
		{
			return _pnode != s._pnode;
		}

		self& operator++ ()
		{
			_pnode = _pnode->_next;
			return *this;
		}
	};

	template <class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T> iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}
	public:
		list()
		{
			//_head = new node(T());
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}
	public:
		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* _tail = _head->_prev;
			_tail->_next = newnode;
			newnode->_prev = _tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
	private:
		node* _head;
	};
};