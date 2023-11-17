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
	//указатели на корень и на текущий узел
	TreeNode<T>* root;
	TreeNode<T>* current;
	
	//число элементов дерева
	int size;

	//используется деструктором, копирования и оператором присваивания
	TreeNode<T>* FindNode(const T& item) const;
public:
	BinSTree();

	//Класс итератора
	class iteratorBST {
	private:
		TreeNode<T>* current1;				//указатель на узел
		std::stack<TreeNode<T>*> stack;		//использеум стек для хранения данных

		//Добавить узел в стек 
		void pushNodes(TreeNode<T>* node) {
			while (node != nullptr) {
				stack.push(node);
				node = node->left;
			}
		}
	public:
		//итератор
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
		//оператор сравнения 
		bool operator!=(const iteratorBST& other) const {
			return current1 != other.current1;
		}
		//оператор вывода узла
		T operator*() const {
			return current1->data;
		}
		//оператор добавления узла 
		iteratorBST& operator++() {
			//если правого потомока нет 
			if (current1->right != nullptr) {
				pushNodes(current1->right);
			}
			//если стек не пустой  
			if (!stack.empty()) {
				current1 = stack.top();	//вернуть указательн на вершину
				stack.pop();			//поместить значение в стек
			}
			else {		//иначе возвращаем, что стек пуст
				current1 = nullptr;
			}
			return *this;
		}
	};
	//итераторы, указывающие на начало и конец дерева соответственно
	iteratorBST begin() {
		return iteratorBST(root);
	}
	iteratorBST end() {
		return iteratorBST(nullptr);
	}


		//стандартные методы обработки списков
		int Find(T& item);
		void Insert(const T& item);
		void Delete(const T& item);
		void Update(const T& item);
		void treevactor(std::vector<T>& vec);
};

//todo диструктор, оператор присваивания конструктор копировани, констр перемещения, оператор = присваивания перемещения 
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
	current = FindNode(item);

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
	//t-текущий узел, parent-предыдущий узел
	TreeNode<T>* t = root, * parent = nullptr, * newNode;
	//закончить на пустом дереве
	while (t !=nullptr)
	{
		//обновить указатель parent и идти направа или влево
		parent = t;
		if (item < t->data)
			t = t->left;
		else
			t = t->right;
	}
	//если родителя нет, вставить в качестве корневого узла
	newNode = GetTreeNode<T>(item, nullptr, nullptr);
	if (parent == nullptr)
		root = newNode;
	//если item меньше родительского узла, вставить в качестве левого сына
	else if (item < parent->data)
		parent->left = newNode;
	else
		//если item больше или равен родительскому узлу
		//вставить  в качесте правого сына
		parent->right = newNode;
	//присвоить указателю current адрес нового узла и увеличить size на 1
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
	if ((DNodePtr = FindNode(item)) == nullptr)
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

template<class T>
void BinSTree<T>::Update(const T& item)
{
	//если текущий узел определен и элемент данных (item) совпал
	if (current != nullptr && current->data ==item)
//с данными в том узле, переписать жэлемент данных в узел
		current->data = item;
	else
		Insert(item);//иначе включить item в дерево
}

//поиск элемента данных в дереве, если найден вернуть адрес
//совпавшего узела или указатель на его родителя иначе NULL
template<class T>
TreeNode<T>* BinSTree<T>::FindNode(const T& item) const
{
	//пробежать по узлам дерева, начиная с корня
	TreeNode<T>* t = root;

	//у корня нет родителя
	TreeNode<T>* parent = nullptr;

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
void BinSTree<T>::treevactor(std::vector<T>& vec) {
	
	if (root != nullptr) {
		vactornode(root->left, vec);
		vec.push_back(root->data);
		vactornode(root->right, vec);
	}
}
