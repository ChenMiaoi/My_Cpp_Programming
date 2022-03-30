#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	
	int _bf;	//平衡因子 -- 规定计算方式为：
				//			1. 新增节点在parent的右边，parent->bf++
				//			2. 新增节点在parent的左边, parent->bf--
				//			a. 如果parent的平衡因子等于1 or -1继续往上更新 -- 说明parent所在子树的高度变了
				//			b. 如果parent的平衡因子等于0 停止更新
				//			c. 如果parent的平衡因子等于2 or -2说明已经不平衡，需要旋转处理
	pair<K, V> _kv;
	AVLTreeNode(const pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	~AVLTree()
	{

	}
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = _root, * cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		/*
			一个节点的平衡因子是否更新，取决于，他的左右子树的高度是否变化
			插入一个节点，这个节点的祖先节点的平衡因子可能需要更新
			a. 如果parent的平衡因子等于1 or -1继续往上更新 -- 说明parent所在子树的高度变了
			b. 如果parent的平衡因子等于0 停止更新 -- 高度不变
			c. 如果parent的平衡因子等于2 or -2说明已经不平衡，需要旋转处理
		*/

		//控制平衡
		//1.更新平衡因子
		//2.如果出现不平衡，则旋转
		while (cur != _root)
		{
			if (parent->left == cur)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//parent所在的子树高度变了，会印象parent->parent
				//继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent所在的子树已经不平衡，需要旋转处理以下
			}
			else
			{
				//插入节点之前，树已经不平衡了，或者bf出错。需要检查其他逻辑
				assert(false);
			}
		}
		return true;
	}

	Node* Find(const K& key)
	{
		return nullptr;
	}

	bool Erase(const K& key)
	{
		return false;
	}
private:
	Node* _root;
};