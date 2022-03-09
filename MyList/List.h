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

	template <class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> self;

		node* _pnode;
		_list_iterator(node* pnode)
			: _pnode(pnode)
		{}

		//拷贝构造、operator=、析构用系统生成的就行
		//要的就是浅拷贝，让拷贝的地址一样

		//节点的指针原生行为不满足迭代器定义
		//这里迭代器通过类去封装节点的指针，重载运算符来控制
		//自定义类型 (*T&).xxx
		Ref operator* ()
		{
			return _pnode->_val;
		}

		//自定义类型 (T*)->xxx
		Ptr operator-> ()
		{
			return &_pnode->_val;
		}

		bool operator!= (const self& s) const
		{
			return _pnode != s._pnode;
		}

		bool operator== (const self& s)	const
		{
			return _pnode == s._pnode;
		}

		self& operator++ ()
		{
			_pnode = _pnode->_next;
			return *this;
		}

		self operator++ (int)
		{
			self temp(*this);
			_pnode = _pnode->_next;
			return temp;
		}

		self& operator-- ()
		{
			_pnode = _pnode->_prev;
			return *this;
		}

		self operator-- (int)
		{
			self temp(*this);
			_pnode = _pnode->_prev;
			return temp;
		}
	};

	template <class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		//只能比读，不能写，_list_iterator<T>中如何控制？
		//typedef _list_const_iterator<T> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator begin() const
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}	

		iterator end()	const
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
			/*node* newnode = new node(x);
			node* _tail = _head->_prev;
			_tail->_next = newnode;
			newnode->_prev = _tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{

		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos->_pnode;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			node* prev = pos->_pnode->_prev;
			node* next = pos->_pnode->_next;
			delete pos->_pnode;
			prev->_next = next;
			next->_prev = prev;

			return iterator(next);
		}
	private:
		node* _head;
	};
};