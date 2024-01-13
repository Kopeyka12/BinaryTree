//@avtor ������� �. �.
//����� ��������� ��� ��������� ������ ������
#pragma once
#include <iostream>
#include <stdlib.h>
#include "iterstor.h"
#include "treenode.h"
#include "treelib.h"
#include <stack>
#include <vector>

template <class T>
class BinSTree
{
private:
	//��������� �� ������ � �� ������� ����
	TreeNode<T>* root;
	TreeNode<T>* current;
	
	//����� ��������� ������
	int size;

	//������������ ������������, ����������� � ���������� ������������
	TreeNode<T>* FindNode(const T& item) const;
public:
	BinSTree();
	BinSTree(TreeNode<T>* tree);

	// ����������
	~BinSTree() { DeleteTree(this->root); }
	//����� ���������
	class iteratorBST {
	private:
		TreeNode<T>* current1;				//��������� �� ����
		std::stack<TreeNode<T>*> stack;		//���������� ���� ��� �������� ������

		//�������� ���� � ���� 
		void pushNodes(TreeNode<T>* node) {
			while (node != nullptr) {
				stack.push(node);
				node = node->left;
			}
		}
	public:
		//��������
		iteratorBST(TreeNode<T>* root) {
			pushNodes(root);
			if (!stack.empty()) {
				current = stack.top();
				stack.pop();
			}
			else {
				current = nullptr;
			}
		}
		//�������� ��������� 
		bool operator!=(const iteratorBST& other) const {
			return current1 != other.current1;
		}
		//�������� ������ ����
		T operator*() const {
			return current1->data;
		}
		//�������� ���������� ���� 
		iteratorBST& operator++() {
			//���� ������� �������� ��� 
			if (current1->right != nullptr) {
				pushNodes(current1->right);
			}
			//���� ���� �� ������  
			if (!stack.empty()) {
				current1 = stack.top();	//������� ���������� �� �������
				stack.pop();			//��������� �������� � ����
			}
			else {		//����� ����������, ��� ���� ����
				current1 = nullptr;
			}
			return *this;
		}
	};
	//���������, ����������� �� ������ � ����� ������ ��������������
	iteratorBST begin() {
		return iteratorBST(root);
	}
	iteratorBST end() {
		return iteratorBST(nullptr);
	}


		//����������� ������ ��������� �������
		int Find(const T& item) const;
		void Insert(const T& item);
		void Delete(const T& item);
		void Update(const T& item);
		void treevactor(std::vector<T>& vec);
};

//todo ����������, �������� ������������ ����������� ����������, ������ �����������, �������� = ������������ ����������� 
template<class T>
BinSTree<T>::BinSTree()
{
	TreeNode<T>* root = nullptr; TreeNode<T>* current = nullptr; int size = 0;
}

// ����������� � �����������
template <typename T>
BinSTree<T>::BinSTree(TreeNode<T>* tree)
{
	this->root = CopyTree(tree);
	this->current = nullptr;
	this->size = treeCount(this->root);
}

//������ item, ���� ������, ��������� ������ ���� ��������� item
template<class T>
int BinSTree<T>::Find(const T& item)const
{
	return SearchNode(this->root, item);
}

//�������� item � ������ ������
template<class T>
void BinSTree<T>::Insert(const T& item)
{
	this->root = GetTreeNode(this->root, item);
	size = treeCount(this->root);
}

//���� ������� ���������� � ������, �� ������� ���
template<class T>
void BinSTree<T>::Delete(const T& item)
{
	this->root = DeleteNode(this->root, item);
	size = treeCount(this->root);
}

template<class T>
void BinSTree<T>::Update(const T& item)
{
	//���� ������� ���� ��������� � ������� ������ (item) ������
	if (current != nullptr && current->data ==item)
//� ������� � ��� ����, ���������� �������� ������ � ����
		current->data = item;
	else
		Insert(item);//����� �������� item � ������
}

//����� �������� ������ � ������, ���� ������ ������� �����
//���������� ����� ��� ��������� �� ��� �������� ����� NULL
template<class T>
TreeNode<T>* BinSTree<T>::FindNode(const T& item) const
{
	//��������� �� ����� ������, ������� � �����
	TreeNode<T>* t = root;

	//� ����� ��� ��������
	TreeNode<T>* parent = nullptr;

	//����������� �� ������ ������
	while (t != nullptr)
	{
		//��������������� �� ����������
		if (item == t->data)
			break;
		else
		{
		//�������� ������������ ��������� � ���� ������� ��� �����
			parent = t;
			if (item < t->data)
				t = t->left;
			else
				t = t->right;
		}
	}
	//���������� ��������� �� ���� ����� nillptr ���� �� ������
	return t;
}

//�������������� ��������� ������ ������ � ������
template< typename T >
void BinSTree<T>::treevactor(std::vector<T>& vec) {
	
	if (root != nullptr) {
		vactornode(root->left, vec);
		vec.push_back(root->data);
		vactornode(root->right, vec);
	}
}
