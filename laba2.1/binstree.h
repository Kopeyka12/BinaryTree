#pragma once
#include <iostream>
#include <stdlib.h>

#include "treenode.h"
#include "treelib.h"
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
	
	//void tree2vactor(BinSTree<T>* root, std::vector<T>& vec);

	//������������ ������������, ����������� � ���������� ������������
	TreeNode<T>* FindNode(const T& item, TreeNode<T>*& parent) const;

	


public:
	BinSTree();
	
	//����������� ������ ��������� �������
	int Find(T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	
	void Update(const T& item);

	BinSTree<T>* BSTInorder(BinSTree<T>* parent);
	
	void tree3vactor(std::vector<T>& vec);
};

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
	current = FindNode(item, parent);

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
	TreeNode<T>* t = root, * parent = nullptr, * newNode;

	while (t !=nullptr)
	{
		parent = t;
		if (item < t->data)
			t = t->left;
		else
			t = t->right;
	}

	newNode = GetTreeNode<T>(item, nullptr, nullptr);
	if (parent == nullptr)
		root = newNode;
	else if (item < parent->data)
		parent->left = newNode;
	else
		parent->right = newNode;
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
	if ((DNodePtr = FindNode(item, PNodePtr)) == nullptr)
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

//���� ������� ���� ��������� � ������� ������ (item) ������
//� ������� � ���� ����, ���������� �������� ������ � ����
//����� �������� item � ������
template<class T>
void BinSTree<T>::Update(const T& item)
{
	if (current != nullptr && current->data ==item)
		current->data = item;
	else
		Insert(item);
}





//����� �������� ������ � ������, ���� ������ ������� �����
//���������� ����� ��� ��������� �� ��� �������� ����� NULL
template<class T>
TreeNode<T>* BinSTree<T>::FindNode(const T& item, TreeNode<T>*& parent) const
{
	//��������� �� ����� ������, ������� � �����
	TreeNode<T>* t = root;

	//� ����� ��� ��������
	parent = nullptr;

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
void BinSTree<T>::tree3vactor(std::vector<T>& vec) {
	
	if (root != nullptr) {
		tree2vactor(root->left, vec);
		vec.push_back(root->data);
		tree2vactor(root->right, vec);
	}
}
