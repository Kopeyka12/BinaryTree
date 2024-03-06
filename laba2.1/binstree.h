//@avtor Мирошин В. И.
//Класс Итератора для бинарного дрерва поиска
#pragma once
#include <iostream>
#include <stdlib.h>
#include "iterstor.h"
#include "AbsIterator.h"
#include "treenode.h"
#include "treelib.h"
#include <stack>
#include <vector>

template <class T>
class BinSTree
{
private:
	//указатели на корень и на текущий узел
	TreeNode<T>* root;
	TreeNode<T>* current;
	
	//число элементов дерева
	int size;

	//используется деструктором, копирования и оператором присваивания
	TreeNode<T>* FindNode(const T& item) const;
public:
	BinSTree();
	//конструктор с параметром
	BinSTree(TreeNode<T>* tree);

	//конструктор копирования
	BinSTree(const BinSTree<T>& tree);

	//оператор копирования (присваивания)
	BinSTree<T>& operator= (const BinSTree<T>& rhs);

	// деструктор
	~BinSTree() { DeleteTree(this->root); }
	

	// класс итератора для BinSTree (симметричный обход, т.е. по возрастанию)
	template<typename T>
	class BinSTreeIterator : public AbsIterator<T> {
	private:
		TreeNode<T>* curr;  // Текущий узел
		std::stack<TreeNode<T>*> path;  // Стек для хранения пути к текущему узлу

	public:
		// конструктор с параметром (в качестве параметра передаётся корень дерева)
		// curr присваивается самый левый узел (наименьший)
		BinSTreeIterator(TreeNode<T>* x) {
			TreeNode<T>* tmp = x;
			while (tmp != nullptr) {
				path.push(tmp);
				tmp = tmp->Left();
			}
			if (!path.empty()) {
				curr = path.top();
				path.pop();
			}
			else {
				curr = nullptr;
			}

		}

		// оператор сравнения
		bool operator==(const AbsIterator<T>& o) const override {
			return curr == dynamic_cast<const BinSTreeIterator<T>&>(o).curr;
		}

		bool operator!=(const AbsIterator<T>& o) const override {
			return !(curr == dynamic_cast<const BinSTreeIterator<T>&>(o).curr);
		}

		// оператор доступа к данным
		T operator*() const override {
			//возвращает данные текущего узла
			return curr->Data();
		}

		// оператор перехода на следующий узел
		BinSTreeIterator& operator++() override {
			if (curr != nullptr) {

				// Если текущий узел имеет правого потомка, идем вправо
				if (curr->Right() != nullptr) {
					curr = curr->Right();

					// Идем влево до последнего левого потомка
					while (curr->Left() != nullptr) {
						path.push(curr);
						curr = curr->Left();
					}
				}
				// Если текущий узел не имеет правого потомка, идем вверх по стеку
				else if (!path.empty()) {
					curr = path.top();
					path.pop();
				}
				// Если стек пуст и нет правого потомка, достигнут конец дерева
				else {
					curr = nullptr;
				}
			}
			return *this;
		}
	};

	BinSTreeIterator<T> begin() const {
		return BinSTreeIterator<T>(root);
	}

	BinSTreeIterator<T> end() const {
		return BinSTreeIterator<T>(nullptr);
	}

	//стандартные методы обработки списков
	int Find(const T& item) const;
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList();
	void treevactor(std::vector<T>& vec);
};

//todo диструктор, оператор присваивания, конструктор копировани, оператор = присваивания

template<class T>
BinSTree<T>::BinSTree()
{
	TreeNode<T>* root = nullptr; TreeNode<T>* current = nullptr; int size = 0;
}

//конструктор с параметрами
template <typename T>
BinSTree<T>::BinSTree(TreeNode<T>* tree)
{
	this->root = CopyTree(tree);
	this->current = nullptr;
	this->size = treeCount(this->root);
}

//конструктор копирования
template <typename T>
BinSTree<T>::BinSTree(const BinSTree<T>& tree)
{
	this->root = CopyTree(tree.root);

	//присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = tree.size;
}


// оператор копирования (присваивания)
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
{
	// нельзя копировать дерево в само себя
	if (this == &rhs)
		return *this;

	// очистить текущее дерево
	ClearList();

	// скопировать новое дерево в текущий объект
	this->root = CopyTree(rhs.root);

	// присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = rhs.size;

	// возвратить ссылку на текущий объект
	return *this;
}

//искать item, если найден, присвоить данные узла параметру item
template<class T>
int BinSTree<T>::Find(const T& item)const
{
	return SearchNode(this->root, item);
}

//вставить item в дерева поиска
template<class T>
void BinSTree<T>::Insert(const T& item)
{
	this->root = GetTreeNode(this->root, item);
	size = treeCount(this->root);
}

//если элемент находиться в дереве, то удалить его
template<class T>
void BinSTree<T>::Delete(const T& item)
{
	this->root = DeleteNode(this->root, item);
	size = treeCount(this->root);
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


// очистка дерева
template <typename T>
void BinSTree<T>::ClearList() {
	deleteTree(this->root);
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}