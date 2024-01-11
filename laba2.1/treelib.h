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
    T Data() const;
    void SetData(T data1);

    void SetRight(TreeNode<T>* right1);

    void SetLeft(TreeNode<T>* left1);

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

// Метод задания значения поля данных
template <typename T>
void TreeNode<T>::SetData(T data1) {
    this->data = data1;
}


// Метод задания значения правого потомка
template <typename T>
void TreeNode<T>::SetRight(TreeNode<T>* right1) {
    this->right = right1;
}

// Метод задания значения левого потомка
template <typename T>
void TreeNode<T>::SetLeft(TreeNode<T>* left1) {
    this->left = left1;
}

// Метод Data возвращает значение поля данных
template <typename T>
T TreeNode<T>::Data() const
{
    return this->data;
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

// Нахождение минимального узла в поддереве
template <typename T>
TreeNode<T>* getNextLeft(TreeNode<T>* root)
{
    while (root->Left() != nullptr) {
        root = root->Left();
    }

    return root;
}

// нахождение ближайшего наибольшего
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

    // Базовый случай (пустое дерево)
    if (root == nullptr) {
        succ = nullptr;
    }

    // если найден узел, для которого нужно найти ближайшее наибольшее
    else if (root->data == key)
    {
        // если есть правый потомок
        if (root->Right() != nullptr) {
            // находим самый левый узел от правого потомка
            succ = getNextLeft(root->Right());
        }
    }

    // поиск нужного узла в левом или правом поддереве
    else if (key < root->data)
    {
        succ = root;
        Successor(root->Left(), succ, key);
    }
    else {
        Successor(root->Right(), succ, key);
    }
}


// Рекурсивный метод для удаления узла из дерева
template <typename T>
TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {

    // базовый случай
    if (root == nullptr) {
        return root;
    }

    // рекурсивный вызов функции, пока не будет найден узел, который нужно удалить
    if (root->Data() > value) {
        root->SetLeft(DeleteNode(root->Left(), value));
        return root;
    }
    else if (root->Data() < value) {
        root->SetRight(DeleteNode(root->Right(), value));
        return root;
    }

    // Когда найден узел на удаление

    // Случаи 1 и 2. если есть только 1 потомок или удалить необходимо лист (0 потомков)
    // если нет левого потомка, то правый поднимается на место удаляемого узла
    if (root->Left() == nullptr) {
        TreeNode<T>* temp = root->Right();
        delete root;
        return temp;
    }
    // если нет правого потомка, то левый поднимается на место удаляемого узла
    else if (root->Right() == nullptr) {
        TreeNode<T>* temp = root->Left();
        delete root;
        return temp;
    }

    // Случай 3. если есть оба потомка
    else {

        // узел, который является родителем ближайшего наибольшего
        TreeNode<T>* succParent = root;

        // Находим ближайшее наибольшее (самый левый узел в правом поддереве) и его родителя
        TreeNode<T>* succ = root->Right();
        while (succ->Left() != nullptr) {
            succParent = succ;
            succ = succ->Left();
        }


        // задача сводится к случаю удаления узла только с правым потомком
        // правого потомка ближайшего наибольшего делаем левым потомком родителя
        // ближайшего наибольшего

        if (succParent != root)
            succParent->SetLeft(succ->Right());
        else
            // если спуска по левому поддереву не было
            succParent->SetRight(succ->Right());


        // данные из ближайшего наибольшего переносятся на место удаляемого узла
        root->SetData(succ->Data());

        // Удаляем ближайшее наибольшее
        delete succ;
        return root;
    }
    
    
    //if (root == nullptr) {
    //    return root;
    //}

    //// Если значение ключа меньше значения корневого узла, рекурсивно ищем узел в левом поддереве
    //if (key < root->data) {
    //    root->left = DeleteNode(root->left, key);
    //}
    //// Если значение ключа больше значения корневого узла, рекурсивно ищем узел в правом поддереве
    //else if (key > root->data) {
    //    root->right = DeleteNode(root->right, key);
    //}
    //// Если значение ключа равно значению корневого узла, то это узел, который нужно удалить
    //else {
    //    // Если у узла нет потомков или только один потомок, то просто удаляем узел, заменяя его на соответствующего потомка
    //    if (root->left == nullptr) {
    //        TreeNode<T>* temp = root->right;
    //        delete root;
    //        return temp;
    //    }
    //    else if (root->right == nullptr) {
    //        TreeNode<T>* temp = root->left;
    //        delete root;
    //        return temp;
    //    }

    //    // Если у узла есть два потомка, то находим наименьший узел в правом поддереве (или наибольший в левом поддереве)
    //    // и заменяем текущий узел на найденный узел, а затем удаляем найденный узел
    //    TreeNode<T>* temp = root->right;
    //    while (temp->left != nullptr) {
    //        temp = temp->left;
    //    }

    //    root->data = temp->data;
    //    root->right = DeleteNode(root->right, temp->data);
    //}

    //return root;
}