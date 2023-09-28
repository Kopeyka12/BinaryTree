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
	//указатели на корень и на текущий узел
	TreeNode<T>* root;
	
	TreeNode<T>* current;
	
	//число элементов дерева
	int size;
	
	//void tree2vactor(BinSTree<T>* root, std::vector<T>& vec);

	//используется деструктором, копирования и оператором присваивания
	TreeNode<T>* FindNode(const T& item, TreeNode<T>*& parent) const;

	


public:
	BinSTree();
	
	//стандартные методы обработки списков
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

//искать item, если найден, присвоить данные узла параметру item
template<class T>
int BinSTree<T>::Find(T& item)
{
	//используем FindNode принимающий параметр parent
	TreeNode<T>* parent;
	
	//искать item назначить совпавший узел текущим
	current = FindNode(item, parent);

	//если найден, присвоить данные узла и возвратить True
	if (current!= nullptr)
	{
		item = current->data;
		return 1;
	}
	else
		//item не нейден, возвратим False
		return 0;
}

//вставить item в дерева поиска
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

//если элемент находиться в дереве, то удалить его
template<class T>
void BinSTree<T>::Delete(const T& item)
{
	//DNodePtr - указатель на удаляемый узел D
	//PNodePtr - указатель на родительский узел P узла D
	//RNodePtr - указатель узл R, замещающий узел D
	TreeNode<T>* DNodePtr, * PNodePtr, * RNodePtr;

	//найти узел, данные в котором совпадают с item
	//получить его адрес и адрес его родителя
	if ((DNodePtr = FindNode(item, PNodePtr)) == nullptr)
		return;
	//если узел D имеет nullptr-указатель, то заменяющим
	//узлом является тот, чо находится на другой ветви
	if (DNodePtr->right == nullptr)
		RNodePtr = DNodePtr->left;
	else if (DNodePtr->left == nullptr)
		RNodePtr = DNodePtr->right;

	//если узел D имеет двух сыновей
	else
	{
		//найти и отсоединить заменяющий узел R для узла D
		//в левом поддерове узла D найти максимальный узел
		//из всех узлов, меньших чемузел D
		//отсоединить этот узел от дерева
		//PofRNodePtr - укзатель на родителя заменяющего узла
		TreeNode<T>* PofRNodePtr = DNodePtr;
		
		//первой возможной заменой является левый сын узла D
		RNodePtr = DNodePtr->left;

		//спуститься вниз по прравому поддереву левого сына узла D,
		//сохраняя записть текущего узла и его родителя
		//остановившись, мы будем иметь заменяющий узел
		while (RNodePtr->right != nullptr)
		{
			PofRNodePtr = RNodePtr->right;
			RNodePtr = RNodePtr->right;
		};

		if (PofRNodePtr == DNodePtr)
			//левый сын удаляемого узла является заменяющим
			//присоединить правое поддерево узла D к узлу R
			RNodePtr->right = DNodePtr->right;
		else
		{
			//левый сын удаляемого вниз по правой ветви как минимум на один узел
			//удалить заменяющий узел из дерева
			//присоединив его правую ветвь к родительскому узлу
			PofRNodePtr->right = RNodePtr->left;
		}
	}

	//завершить присоединение к родительсокму узлу
	//удалить корневой узел назначить новый корень
	if (RNodePtr == nullptr)
		root = RNodePtr;
	//присоединить узел R к узлу P c gправильной стороны
	else if (DNodePtr->data < PNodePtr->data)
		PNodePtr->left = RNodePtr;
	else
		PNodePtr->right = RNodePtr;

	//удалить узел из памяти и уменьшить размер списка
	FreeTreeNode(DNodePtr);
	size--;
}

//если текущий узел определен и элемент данных (item) совпал
//с данными в жтом узле, переписать жэлемент данных в узел
//иначе включить item в дерево
template<class T>
void BinSTree<T>::Update(const T& item)
{
	if (current != nullptr && current->data ==item)
		current->data = item;
	else
		Insert(item);
}





//поиск элемента данных в дереве, если найден вернуть адрес
//совпавшего узела или указатель на его родителя иначе NULL
template<class T>
TreeNode<T>* BinSTree<T>::FindNode(const T& item, TreeNode<T>*& parent) const
{
	//пробежать по узлам дерева, начиная с корня
	TreeNode<T>* t = root;

	//у корня нет родителя
	parent = nullptr;

	//прерываться на пустом дереве
	while (t != nullptr)
	{
		//останавливается по совпадении
		if (item == t->data)
			break;
		else
		{
		//обновить родительский указатель и идти направо или влево
			parent = t;
			if (item < t->data)
				t = t->left;
			else
				t = t->right;
		}
	}
	//возвратить указатель на узел иначе nillptr если не найден
	return t;
}

//Преобразование бинарного поиска дерева в вектор
template< typename T >
void BinSTree<T>::tree3vactor(std::vector<T>& vec) {
	
	if (root != nullptr) {
		tree2vactor(root->left, vec);
		vec.push_back(root->data);
		tree2vactor(root->right, vec);
	}
}
