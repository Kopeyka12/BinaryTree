#pragma once
#include <cassert>
//#include <TestTreeNode.cpp>
//Предварительное описание класса «бинарное дерево поиска»

template <class T>
class BinSTree;

//Определение класса «узел бинарного дерева»
template <class T>
class TreeNode

{
public:
//Указатели на левый и правый порожденные узлы

    TreeNode<T> *left;

    TreeNode<T> *right;


    //Открытый элемент данных класса, допускающий обновление

    T data;

    //Конструктор: инициализирует поле данных и указатели

    //на порожденные узлы

    TreeNode(const T& item, TreeNode<T>* lptr = nullptr, TreeNode<T>* rptr = nullptr);    

    // Методы доступа к указателям на порожденные узлы

    TreeNode<T>* Left() const;

    TreeNode<T>* Right() const;

    // Описание класса BinSTree как дружественного

    friend class BinSTree<T>;
};

//Создать объект TreeNode с указательными полями lptr и rptr.

//По умолчанию указатели содержат NULL.

template <class T>
TreeNode<T>::TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr) :
    
    data(item), left(lptr), right(rptr) { }

template<class T>
inline TreeNode<T>* TreeNode<T>::Left() const
{
    return left;
}

template<class T>
inline TreeNode<T>* TreeNode<T>::Right() const
{
    return right;
}


//создает объект TreeNode с указательными полями lptr и rptr
//по умолчанию указатели nullptr
template <class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,

    TreeNode<T>* rptr = nullptr)//
{
    TreeNode<T>* p;
    //Вызвать new для создания нового узла
    
    //Передать туда параметры lptr и rptr

    p = new TreeNode<T>(item, lptr, rptr);

    //Если памяти недостаточно, завершить
    
    //программу сообщением об ошибке

    if (p == nullptr)
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

//используем обратный аллгоритм прохождения 
//удаляем каждый узел при его посещении
template <class T>
void DeleteTree(TreeNode<T>* t)
{
    if (t != nullptr) {
        DeleteTree(t->Left());
        DeleteTree(t->Right());
        FreeTreeNode(t);
    }
}

//вызфваем ф-ию для удаления узлов дерева
//затем сбрасываем указатель на его корень в nullptr
template <class T>
void ClearTree(TreeNode<T>& t)
{
    DeleteTree(t);
    t = nullptr;
}


