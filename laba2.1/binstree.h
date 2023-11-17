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
protected:
	//��������� �� ������ � �� ������� ����
	TreeNode<T>* root;
	TreeNode<T>* current;
	
	//����� ��������� ������
	int size;

	//������������ ������������, ����������� � ���������� ������������
	TreeNode<T>* FindNode(const T& item) const;
public:
	BinSTree();

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
		int Find(T& item);
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

//������ item, ���� ������, ��������� ������ ���� ��������� item
template<class T>
int BinSTree<T>::Find(T& item)
{
	//���������� FindNode ����������� �������� parent
	TreeNode<T>* parent;
	
	//������ item ��������� ��������� ���� �������
	current = FindNode(item);

	//���� ������, ��������� ������ ���� � ���������� True
	if (current!= nullptr)
	{
		item = current->data;
		return 1;
	}
	else
		//item �� ������, ��������� False
		return 0;
}

//�������� item � ������ ������
template<class T>
void BinSTree<T>::Insert(const T& item)
{
	//t-������� ����, parent-���������� ����
	TreeNode<T>* t = root, * parent = nullptr, * newNode;
	//��������� �� ������ ������
	while (t !=nullptr)
	{
		//�������� ��������� parent � ���� ������� ��� �����
		parent = t;
		if (item < t->data)
			t = t->left;
		else
			t = t->right;
	}
	//���� �������� ���, �������� � �������� ��������� ����
	newNode = GetTreeNode<T>(item, nullptr, nullptr);
	if (parent == nullptr)
		root = newNode;
	//���� item ������ ������������� ����, �������� � �������� ������ ����
	else if (item < parent->data)
		parent->left = newNode;
	else
		//���� item ������ ��� ����� ������������� ����
		//��������  � ������� ������� ����
		parent->right = newNode;
	//��������� ��������� current ����� ������ ���� � ��������� size �� 1
	current = newNode;
	size++;
}

//���� ������� ���������� � ������, �� ������� ���
template<class T>
void BinSTree<T>::Delete(const T& item)
{
	//DNodePtr - ��������� �� ��������� ���� D
	//PNodePtr - ��������� �� ������������ ���� P ���� D
	//RNodePtr - ��������� ��� R, ���������� ���� D
	TreeNode<T>* DNodePtr, * PNodePtr, * RNodePtr;

	//����� ����, ������ � ������� ��������� � item
	//�������� ��� ����� � ����� ��� ��������
	if ((DNodePtr = FindNode(item)) == nullptr)
		return;
	//���� ���� D ����� nullptr-���������, �� ����������
	//����� �������� ���, �� ��������� �� ������ �����
	if (DNodePtr->right == nullptr)
		RNodePtr = DNodePtr->left;
	else if (DNodePtr->left == nullptr)
		RNodePtr = DNodePtr->right;

	//���� ���� D ����� ���� �������
	else
	{
		//����� � ����������� ���������� ���� R ��� ���� D
		//� ����� ��������� ���� D ����� ������������ ����
		//�� ���� �����, ������� ������� D
		//����������� ���� ���� �� ������
		//PofRNodePtr - �������� �� �������� ����������� ����
		TreeNode<T>* PofRNodePtr = DNodePtr;
		
		//������ ��������� ������� �������� ����� ��� ���� D
		RNodePtr = DNodePtr->left;

		//���������� ���� �� �������� ��������� ������ ���� ���� D,
		//�������� ������� �������� ���� � ��� ��������
		//�������������, �� ����� ����� ���������� ����
		while (RNodePtr->right != nullptr)
		{
			PofRNodePtr = RNodePtr->right;
			RNodePtr = RNodePtr->right;
		};

		if (PofRNodePtr == DNodePtr)
			//����� ��� ���������� ���� �������� ����������
			//������������ ������ ��������� ���� D � ���� R
			RNodePtr->right = DNodePtr->right;
		else
		{
			//����� ��� ���������� ���� �� ������ ����� ��� ������� �� ���� ����
			//������� ���������� ���� �� ������
			//����������� ��� ������ ����� � ������������� ����
			PofRNodePtr->right = RNodePtr->left;
		}
	}

	//��������� ������������� � ������������� ����
	//������� �������� ���� ��������� ����� ������
	if (RNodePtr == nullptr)
		root = RNodePtr;
	//������������ ���� R � ���� P c g���������� �������
	else if (DNodePtr->data < PNodePtr->data)
		PNodePtr->left = RNodePtr;
	else
		PNodePtr->right = RNodePtr;

	//������� ���� �� ������ � ��������� ������ ������
	FreeTreeNode(DNodePtr);
	size--;
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
