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
		_Destroy(_root);
		_root = nullptr;
	}
public:
	V& operator[] (const K& key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second;
	}

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
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
				return make_pair(cur, false);
		}
		cur = new Node(kv);
		Node* newnode = cur;
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
		return make_pair(newnode, true);
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
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		//平衡因子的调节...
		if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
			subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == 0)
			parent->_bf = subL->_bf = subLR->_bf = 0;
		else
			assert(false);
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
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
				cur = cur->_right;
			else if (cur->_kv.first > key)
				cur = cur->_left;
			else
				return cur;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		/*
			1.先找到删除值所在的节点
			2.按搜索树的规则分类删除。
				a.左为空
				b.右为空
				c.左右都不为空
			3.更新平衡因子(基本上和插入是反着的)，如果出现不平衡->旋转
				a.删除在parent的左，平衡因子++
				b.删除在parent的右，平衡因子--
				c.更新后，parent->_bf == 0，说明原来是1或者-1，把高的删除了，高度变了，要继续向上更新
				d.更新后parent->_bf == 1 || parent->_bf == -1，说明原来是0，现在把一边删除了一个，parent的高度不变，不影响上一层，停止更新
				e.更新后parent->_bf == 2或者-2，不平衡->旋转
		*/
		return false;
	}

	bool IsAVLTree()
	{
		return _IsBalance(_root);
	}

	int Height()
	{
		return _Height(_root);
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
	}
	void InOrder()
	{
		_InOrder(_root);
	}
	void PostOrder()
	{
		_PostOrder(_root);
	}
protected:
	void _Destroy(Node* root)
	{
		if (root == nullptr)
			return;
		_Destroy(root->_left);
		_Destroy(root->_right);
		delete root;
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;

	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		//检查一下平衡因子是否正确
		if (rightHeight - leftHeight != root->_bf)
		{
			cout << "平衡因子异常:> " << root->_kv.first << endl;
			return false;
		}
		return abs(rightHeight - leftHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}
	void _PrevOrder(Node* root)
	{
		if (root == nullptr)
			return;
		cout << root->_kv.first << " : " << root->_kv.second << endl;
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " : " << root->_kv.second << endl;
		_InOrder(root->_right);
	}
	void _PostOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_kv.first << " : " << root->_kv.second << endl;
	}
private:
	Node* _root;
};