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
			if (parent->_left == cur)
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
				//右单旋 ：遵循搜索树规则，尽量让两边平衡
				//1.根的左子树的右子树去做根的左子树
				//2.根以及根的右子树去做根左子树的右子树
				//根的左节点就做现在的根
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
						RotateR(parent);	//右单旋
					else	// cur->_bf == 1
						RotateLR(parent);
				}
				else
				{
					if (cur->_bf == 1)
						RotateL(parent);
					else	// cur->_bf == -1
						RotateRL(parent);
				}
				break;
			}
			else
			{
				//插入节点之前，树已经不平衡了，或者bf出错。需要检查其他逻辑
				assert(false);
			}
		}
		return true;
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		Node* parentParent = parent->_parent;	//可能这只是一个子树
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

		parent->_bf = subL->_bf = 0;
	}

	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL ;
		if (subRL)
			subRL->_parent = parent;
		Node* parentParent = parent->_parent;	//可能这只是一个子树
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

		parent->_bf = subR->_bf = 0;
	}

	//左右双旋
	//先以左子树为旋转点，进行左单旋
	//再以根为旋转点，进行右单旋
	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
		//平衡因子的调节...

	}

	//右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else
			assert(false);
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