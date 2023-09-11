#pragma once
//#include <iostream>
//Предварительное описание класса «бинарное дерево поиска»

template <class T>
class BinSTree;

//Определение класса «узел бинарного дерева»
template <class T>
class TreeNode

{
    //Указатели на левый и правый порожденные узлы

    TreeNode<T>* left;

    TreeNode<T>* right;

public:
    //Открытый элемент данных класса, допускающий обновление

    T data;

    //Конструктор: инициализирует поле данных и указатели

    //на порожденные узлы

    TreeNode(const T& item, TreeNode<T>* lptr = NULL, TreeNode<T>* rptr = NULL);

    //TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr) :
    //
    //   data(item), left(lptr), right(rptr) { }

    // Методы доступа к указателям на порожденные узлы

    TreeNode<T>* Left(void) const;

    TreeNode<T>* Right(void) const;

    // Описание класса BinSTree как дружественного

    friend class BinSTree<T>;

};

//Создать объект TreeNode с указательными полями lptr и rptr.

//По умолчанию указатели содержат NULL.

template <class T>

TreeNode<T>::TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr) :
    
    data(item), left(lptr), right(rptr) { }

template <class T>

TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = NULL,

    TreeNode<T>* rptr = NULL)
{
    TreeNode<T>* p;
    //Вызвать new для создания нового узла
    //Передать туда параметры lptr и rptr
    p = new TreeNode<T>(item, lptr, rptr);
    //Если памяти недостаточно, завершить
    //программу сообщением об ошибке
    if (p == NULL)
    {
        std::cerr << "Ошибка при выделении памяти!\n";
        exit(1);
    }
    //Вернуть указатель на выделенную системой память
    return p;
}

//Освободить динамическую память, занимаемую данным узлом

template <class T>

void FreeTreeNode(TreeNode<T>* p)

{

    delete p;

}