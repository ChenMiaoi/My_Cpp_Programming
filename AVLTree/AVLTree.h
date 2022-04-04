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
			if (parent->_left == cur)
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
				//�ҵ��� ����ѭ���������򣬾���������ƽ��
				//1.������������������ȥ������������
				//2.���Լ�����������ȥ������������������
				//������ڵ�������ڵĸ�
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
						RotateR(parent);	//�ҵ���
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
				//����ڵ�֮ǰ�����Ѿ���ƽ���ˣ�����bf������Ҫ��������߼�
				assert(false);
			}
		}
		return make_pair(newnode, true);
	}

	//�ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		Node* parentParent = parent->_parent;	//������ֻ��һ������
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

	//����
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL ;
		if (subRL)
			subRL->_parent = parent;
		Node* parentParent = parent->_parent;	//������ֻ��һ������
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

	//����˫��
	//����������Ϊ��ת�㣬��������
	//���Ը�Ϊ��ת�㣬�����ҵ���
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		//ƽ�����ӵĵ���...
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

	//����˫��
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
			1.���ҵ�ɾ��ֵ���ڵĽڵ�
			2.���������Ĺ������ɾ����
				a.��Ϊ��
				b.��Ϊ��
				c.���Ҷ���Ϊ��
			3.����ƽ������(�����ϺͲ����Ƿ��ŵ�)��������ֲ�ƽ��->��ת
				a.ɾ����parent����ƽ������++
				b.ɾ����parent���ң�ƽ������--
				c.���º�parent->_bf == 0��˵��ԭ����1����-1���Ѹߵ�ɾ���ˣ��߶ȱ��ˣ�Ҫ�������ϸ���
				d.���º�parent->_bf == 1 || parent->_bf == -1��˵��ԭ����0�����ڰ�һ��ɾ����һ����parent�ĸ߶Ȳ��䣬��Ӱ����һ�㣬ֹͣ����
				e.���º�parent->_bf == 2����-2����ƽ��->��ת
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

		//���һ��ƽ�������Ƿ���ȷ
		if (rightHeight - leftHeight != root->_bf)
		{
			cout << "ƽ�������쳣:> " << root->_kv.first << endl;
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