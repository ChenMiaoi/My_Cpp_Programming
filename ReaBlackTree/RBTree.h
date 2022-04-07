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

	//拷贝和赋值

	~RBTree()
	{
		_Destory(_root);
		_root = nullptr;
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

		//如果父亲存在且颜色为红色就需要持续处理
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				//情况1：叔叔存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				//情况2+3：叔叔不存在或存在且为黑
				else
				{
					if (cur == parent->_left)	//情况2 -- 单旋
					{
						RotateR(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else	//情况3：双旋
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else	//parent == grandfather->_left
			{
				Node* uncle = grandfather->_left;
				//情况1：叔叔存在且为红
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				//情况2+3：叔叔不存在或存在且为黑
				else
				{
					if (cur == parent->_right)	//情况2 -- 单旋
					{
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else	//情况3：双旋
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		/*
			1.parent颜色是黑色，不需要处理，插入完成
			2.parent颜色是红色，违反规则，需要处理 -- (关键看parent的兄弟)
				a.cur为红，parent为红，parent的兄弟存在并且为红，parent的parent为黑
					-- p和u变黑，g变红，继续向上处理
				b.cur为红，parent为红，parent的parent为黑，parent的兄弟不存在或存在且为黑 -- (由情况1变化而来，直线)
					-- 旋转+变色(p变黑，g变红)
				c.cur为红，parent为红，parent的parent为黑，parent的兄弟不存在或存在且为黑 -- (由情况1变化而来，折线)
					-- 双旋+变色(cur变黑，g变红)
		*/
		return make_pair(newnode, true);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
				cur = cur->_left;
			else if (cur->_kv.first < key)
				cur = cur->_right;
			else
				return cur;
		}
		return nullptr;
	}
protected:
	void _Destory(Node* root)
	{
		if (root == nullptr)
			return;
		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
	}

	//右旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		Node* parentParent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}
	}

	//左旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		Node* parentParent = parent->_parent;	
		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;

			subR->_parent = parentParent;
		}
	}
private:
	Node* _root;
};