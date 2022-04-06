#pragma once
#include <iostream>

using namespace std;

enum Color
{
	RED,
	BLACK
};

template <class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Color _col;

	RBTreeNode(const pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template <class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		: _root(nullptr)
	{}

	~RBTree()
	{

	}
public:
	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}
		
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		Node* newnode = new Node(kv);
		newnode->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		cur = newnode;

		/*
			1.parent��ɫ�Ǻ�ɫ������Ҫ�����������
			2.parent��ɫ�Ǻ�ɫ��Υ��������Ҫ���� -- (�ؼ���parent���ֵ�)
				a.curΪ�죬parentΪ�죬parent���ֵܴ��ڲ���Ϊ�죬parent��parentΪ��
					-- p��u��ڣ�g��죬�������ϴ���
		*/
		return make_pair(newnode, true);
	}
private:
	Node* _root;
};