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
public:
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

	/*
		1. Ҷ�ӽڵ� --> ɾ���Լ���Ȼ����ָ���Լ��ÿ�
		2. ֻ��һ������ --> ɾ���ڵ㣬�Ѻ��ӽ�������
		3. ���������� --> �滻��ɾ����ȥ����������һ�����滻�Լ��Ľڵ�
			�����������ڵ㣬���������ҽڵ��������
			����������С�ڵ㣬����������ڵ������С��
	*/
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
#ifndef NULL
					Node* minRight = cur->_right;
					while (minRight->_left)
						minRight = minRight->_left;
					Key min = minRight->_key;
					//�ݹ�����Լ�ȥɾ���滻�ڵ㣬һ�����ߵ���Ϊ�յ����
					this->Erase(min);
					cur->_key = min;
#endif // !0 �ݹ����

				}
				return true;
			}
		}
		return false;
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