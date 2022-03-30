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
	
	int _bf;	//ƽ������ -- �涨���㷽ʽΪ��
				//			1. �����ڵ���parent���ұߣ�parent->bf++
				//			2. �����ڵ���parent�����, parent->bf--
				//			a. ���parent��ƽ�����ӵ���1 or -1�������ϸ��� -- ˵��parent���������ĸ߶ȱ���
				//			b. ���parent��ƽ�����ӵ���0 ֹͣ����
				//			c. ���parent��ƽ�����ӵ���2 or -2˵���Ѿ���ƽ�⣬��Ҫ��ת����
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
			һ���ڵ��ƽ�������Ƿ���£�ȡ���ڣ��������������ĸ߶��Ƿ�仯
			����һ���ڵ㣬����ڵ�����Ƚڵ��ƽ�����ӿ�����Ҫ����
			a. ���parent��ƽ�����ӵ���1 or -1�������ϸ��� -- ˵��parent���������ĸ߶ȱ���
			b. ���parent��ƽ�����ӵ���0 ֹͣ���� -- �߶Ȳ���
			c. ���parent��ƽ�����ӵ���2 or -2˵���Ѿ���ƽ�⣬��Ҫ��ת����
		*/

		//����ƽ��
		//1.����ƽ������
		//2.������ֲ�ƽ�⣬����ת
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
				//parent���ڵ������߶ȱ��ˣ���ӡ��parent->parent
				//�������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent���ڵ������Ѿ���ƽ�⣬��Ҫ��ת��������
			}
			else
			{
				//����ڵ�֮ǰ�����Ѿ���ƽ���ˣ�����bf������Ҫ��������߼�
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