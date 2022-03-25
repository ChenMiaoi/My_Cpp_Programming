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
#endif // !0 �ǵݹ�汾

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
#endif // !0 �ǵݹ�汾

	/*
		1. Ҷ�ӽڵ� --> ɾ���Լ���Ȼ����ָ���Լ��ÿ�
		2. ֻ��һ������ --> ɾ���ڵ㣬�Ѻ��ӽ�������
		3. ���������� --> �滻��ɾ����ȥ����������һ�����滻�Լ��Ľڵ�
			�����������ڵ㣬���������ҽڵ��������
			����������С�ڵ㣬����������ڵ������С��
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
					//�ҵ���������С�ڵ�
					Node* minRight_parent = cur;	//����˴���ʼ��nullptr������պø���һ������ֵ���򲻻����ѭ��ֱ�ӱ���
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minRight_parent = minRight;
						minRight = minRight->_left;
					}
					//�����滻�ڵ��ֵ
					cur->_key = minRight->_key;
					//ɾ��
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
#endif // !0 �ǵݹ�汾

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
	//Ϊʲô�����ã�  ��ΪҪ���룬����ҵ�Ҫ�����λ��֮�������ò�����"��ַ����"
	//�˴���ָ���Ǿ���
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

	//�˴��������Ǿ���
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
			//�ҵ��ˣ�root����Ҫɾ���Ľڵ�
			if (root->_left == nullptr)
			{
				Node* del = root;
				root = root->_right;	//Ҫ�ø��ڵ�ָ���ҵ���������Ȼ�������Ǹ����������ı���
				delete del;				//���ֱ�����ҵ����ҵ����������������������ҵ�������
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
				//�ҵ���������С�ڵ�
				Node* minRight_parent = root;	//����˴���ʼ��nullptr������պø���һ������ֵ���򲻻����ѭ��ֱ�ӱ���
				Node* minRight = root->_right;
				while (minRight->_left)
				{
					minRight_parent = minRight;
					minRight = minRight->_left;
				}
				//�����滻�ڵ��ֵ
				root->_key = minRight->_key;
				//ɾ��
				if (minRight_parent->_left == minRight)
					minRight_parent->_left = minRight->_right;
				else
					minRight_parent->_right = minRight->_right;
				delete minRight;
#endif	// !0 ��һ�ַ�ʽ��ֻ�ܽ���ԭ����ɾ��

				//�ڶ��֣�����дһ���ݹ� -- ��ʱ�����ò�����Ч
				Node* minRight = root->_right;
				while (minRight->_left)
					minRight = minRight->_left;
				Key min = minRight->_key;
				//ת����root��������ɾ��min
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