#pragma once
#include <iostream>
#include <stdlib.h>
#include "treenode.h"

template <class T>
class BinSTree
{
protected:
	TreeNode<T>* root;
	TreeNode<T>* current;

	int size;

	TreeNode<T>* GetTreeNode(const T& item,
		TreeNode<T>* lptr, TreeNode<T>* rptr);
	void FreeTreeNode(TreeNode<T>* p);

	void DeleteTree(TreeNode<T>* t);

	TreeNode<T>* FindNode(const T& item, TreeNode<T>*& parent) const;


public:
	BinSTree();
	BinSTree(const BinSTree<T>& tree);
	~BinSTree();
	
	BinSTree<T>& operator = (const BinSTree<T>& rhs);

	int Find(T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList();
	int ListEmpty()const;
	int ListSize()const;

	void Update(const T& item);
	TreeNode<T>* GetRoot() const;
};


//оператор присваивания 
template<class T>
BinSTree<T>& BinSTree<T>::operator = (const BinSTree<T>& rhs)
{
	if (this == &rhs)
		return *this;

	ClearList();
	root = CopyTree(tree.root);

	current = root;
	size = tree.size;

	return *this;
}
template<class T>
int BinSTree<T>::Find(T& item)
{
	TreeNode<T>* parent;

	current = FindNode(item, parent);

	if (current!= nullptr)
	{
		item = current->data;
		return 1;
	}
	else
		return 0;
}


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

	if (parent == nullptr)
		root = newNode;
	else if (item < parent->data)
		parent->left = newNode;
	else
		parent->right = newNode;
	current = newNode;
	size++;
}
template<class T>
inline void BinSTree<T>::Delete(const T& item)
{
	TreeNode<T>* DNodePtr, * PNodePtr, * RNodePtr;

	if (DNodePtr = FindNode(item, PNodePtr)) == nullptr
		return;

	if (DNodePtr->right == nullptr)
		RNodePtr = DNodePtr->left;
	else if (DNodePtr->left == nullptr)
		RNodePtr = DNodePtr->right;

	else
	{
		TreeNode<T>* PofRNodePtr = DNodePtr;

		RNodePtr = DNodePtr->left;

		while (RNodePtr ->right != nullptr)
		{
			PofRNodePtr = RNodePtr->right;
			RNodePtr= RNodePtr->right
		}

		if (PofRNodePtr == DNodePtr)
			RNodePtr->right = DNodePtr->right;
		else
		{
			PofRNodePtr->right = RNodePtr->left;
		}
	}

	if (RNodePtr == nullptr)
		root = RNodePtr;
	else if (DNodePtr->data < PNodePtr->data)
		PNodePtr->left = RNodePtr;
	else
		PNodePtr->right = RNodePtr;
	FreeTreeNode(DNodePtr);
	size--;
}
template<class T>
void BinSTree<T>::Update(const T& item)
{
	if (current != nullptr && current T & item)
		current->data = item;
	else
		Insert(item);
}
//поиск элемента данных в дереве, если найден вернуть адрес
//совпавший узел или указатель на его родителя иначе NULL
template<class T>
TreeNode<T>* BinSTree<T>::FindNode(const T& item, TreeNode<T>*& parent) const
{
	TreeNode<T>* t = root;

	parent = nullptr;
	while (t != = nullptr)
	{
		if (item == t->data)
			break;
		else
		{
			parent = t;
			if (item < t->data)
				break;
			else
			{
				parent = t;
				if (item < t->data)
				else
					t = t->right;
			}
		}
	}

	return t;
}
