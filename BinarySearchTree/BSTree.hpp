#pragma once
#include <iostream>
using namespace std;

template <class Key>
struct BSTreeNode
{
	BSTreeNode(const Key& key)
		: _left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
	BSTreeNode<Key>* _left;
	BSTreeNode<Key>* _right;
	Key _key;
};

template <class Key>
class BSTree
{
	typedef BSTreeNode<Key> Node;
public:
	BSTree()
		: _root(nullptr)
	{}

	BSTree(const BSTree<Key>& t)
	{
		this->_root = _Copy(t._root);
	}

	BSTree<Key>& operator= (BSTree<Key> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~BSTree()
	{
		_Destory(_root);
		_root = nullptr;
	}
private:
	void Destory(Node* root)
	{
		if (root == nullptr)
			return;
		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
	}
public:
	bool Insert(const Key& key)
	{
		return _Insert(_root, key);
	}
#if 0
	bool Insert(const Key& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		cur = new Node(key);
		if (parent->_key < key)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}
#endif // !0 非递归版本

	Node* Find(const Key& key)
	{
		return _Find(_root, key);
	}
#if 0
	Node* Find(const Key& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
				cur = cur->_right;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				return cur;
		}
		return nullptr;
	}
#endif // !0 非递归版本

	/*
		1. 叶子节点 --> 删除自己，然后父亲指向自己置空
		2. 只有一个孩子 --> 删除节点，把孩子交给父亲
		3. 有两个孩子 --> 替换法删除，去孩子里面找一个能替换自己的节点
			左子树的最大节点，左子树最右节点就是最大的
			右子树的最小节点，右子树最左节点就是最小的
	*/
#if 0
	bool Erase(const Key& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
						_root = cur->_right;
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
						_root = cur->_left;
					else
					{
						if (parent->_left == cur)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}
				}
				else
				{
					//找到右子树最小节点
					Node* minRight_parent = cur;	//如果此处初始化nullptr，如果刚好给到一个极限值，则不会进入循环直接崩掉
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minRight_parent = minRight;
						minRight = minRight->_left;
					}
					//保存替换节点的值
					cur->_key = minRight->_key;
					//删除
					if (minRight_parent->_left == minRight)
						minRight_parent->_left = minRight->_right;
					else
						minRight_parent->_right = minRight->_right;
					delete minRight;
				}
				return true;
			}
		}
		return false;
	}
#endif // !0 非递归版本

	bool Erase(const Key& key)
	{
		return _Erase(_root, key);
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}
protected:
	//为什么传引用？  因为要插入，最后找到要插入的位置之后传入引用才能是"传址调用"
	//此处的指针是精华
	bool _Insert(Node*& root, const Key& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
			return _Insert(root->_right, key);
		else if (root->_key > key)
			return _Insert(root->_left, key);
		else
			return false;
	}
	Node* _Find(Node* root, const Key& key)
	{
		if (root == nullptr)
			return nullptr;
		if (root->_key < key)
			return _Find(root->_right, key);
		else if (root->_key > key)
			return _Find(root->_left, key);
		else
			return root;
	}

	//此处的引用是精华
	bool _Erase(Node*& root, const Key& key)
	{
		if (root == nullptr)
			return false;
		if (root->_key < key)
			return _Erase(root->_right, key);
		else if (root->_key > key)
			return _Erase(root->_left, key);
		else
		{
			//找到了，root就是要删除的节点
			if (root->_left == nullptr)
			{
				Node* del = root;
				root = root->_right;	//要让父节点指向我的右子树，然而我又是父亲右子树的别名
				delete del;				//因此直接让我等于我的右子树，就是链接上了我的右子树
			}
			else if (root->_right == nullptr)
			{
				Node* del = root;
				root = root->_left;
				delete del;
			}
			else
			{
#if 0
				//找到右子树最小节点
				Node* minRight_parent = root;	//如果此处初始化nullptr，如果刚好给到一个极限值，则不会进入循环直接崩掉
				Node* minRight = root->_right;
				while (minRight->_left)
				{
					minRight_parent = minRight;
					minRight = minRight->_left;
				}
				//保存替换节点的值
				root->_key = minRight->_key;
				//删除
				if (minRight_parent->_left == minRight)
					minRight_parent->_left = minRight->_right;
				else
					minRight_parent->_right = minRight->_right;
				delete minRight;
#endif	// !0 第一种方式，只能借助原生的删除

				//第二种，单独写一个递归 -- 此时的引用不在起效
				Node* minRight = root->_right;
				while (minRight->_left)
					minRight = minRight->_left;
				Key min = minRight->_key;
				//转换在root的右子树删除min
				this->_Erase(root->_right, min);
				root->_key = min;
			}
			return true;
		}
		return false;
	}

	Node* _Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* copyNode = new Node(root->_key);
		copyNode->_left = _Copy(root->_left);
		copyNode->_right = _Copy(root->_right);
		return copyNode;
	}

	void _Destory(Node* root)
	{

	}

	void _PrevOrder(Node* root)
	{
		if (root == nullptr)
			return;
		cout << root->_key << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	void _PostOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_key << " ";
	}

private:
	Node* _root;
};