#pragma once
#include <iostream>
#include <queue>
//симетричное рекурсивное прохождение узлов дерева  LNR
template <class T>
void Inorder(TreeNode<T>* t, void visit(T& item)) {

    //рекурсивное прохождение завершается на пустом поддереве

    if (t != nullptr) {

        Inorder(t->Left(), visit);      //спускаемся по левому поддерову

        visit(t->data);                 //посетить узел

        Inorder(t->Right(), visit);     //спуститься по правому поддереву
    }
}

//ф-ия обхода LRN
template <class T>
void Postorder(TreeNode<T>* t) {

    //рекурсивное прохождение завершается на пустом поддереве

    if (t != nullptr) {

        Postorder(t->Left());      //спускаемся по левому поддерову

        Postorder(t->Right());     //спуститься по правому поддереву

        std::cout << t->data << " ";                 //посетить узел
    }
}
//ф-ия вывода значение узла
template <class T>
void visit_print(T& item) {
    std::cout << item << " ";
}
//ф-ия увеличивает значение узла на 1
template <class T>
void visit_inc(T& item) {
    item++;
}

//использует обратный метод прохождения.
//во время посещения узла проверяется, является ли он листовым
template <class T>
int CountLeaf(TreeNode<T>* t, int& count) {
    
    //обратный метод прохождения
    if (t != nullptr)
    {
        CountLeaf(t->Left(), count);    //пройти левое поддерево
        CountLeaf(t->Right(), count);   //пройти правое поддерево
        
        //проверить, является ли данный узел листом
        //если да, то еувеличиваем count
        if (t->Left() == nullptr && t->Right() == nullptr)
            count++;
    }
    return count;
}



//фу-ия LRN
//вычисляет глубину дерева через формулу
// 1+ max(depthLeft, depthRight)
//глубина пустого дерева равна -1
template <class T>
int Depth(TreeNode<T>* t) {

    int depthLeft, depthRight, depthval;

    if (t == nullptr)

        depthval = -1;
    else
    {
        depthRight = Depth(t->Right());
        
        depthLeft = Depth(t->Left());

        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
        
    }
    return depthval;
}


//промежудки м/у уровнями
const int indentBlock = 4;
//встваить num пробелов на текущей строке
void IndentBlocks(int num)
{
    for (int i = 0; i < num; i++)
        std::cout << " ";
}
//распечатать дерево боком, используя RNL-прохождение
template <class T>
void PrintTree(TreeNode<T>* t, int level)
{
    //печатать дерево с корнем t пока дерево не пустое
    if (t != nullptr) 
    {
        PrintTree(t->Right(), level + 1);   //печатать правое поддерево узла 
        IndentBlocks(indentBlock * level);  //выровнять текущий уровень и вывести поле данных
        std::cout << t->data << std::endl;  
        PrintTree(t->Left(), level + 1);    //печать левого поддерева
    }
}

//создать дубликат дерева t и возвратить корень нового дерева
template<class T>
TreeNode<T>* CopyTree(TreeNode<T>* t) {
    //newnode указывает на новый узел, создаваемый
    //посредством вызова GetTreeNode и присоединяемыйк новому дереву
    //указателей newlptr, newrptr 

    TreeNode<T>* newlptr, * newrptr, * newnode;
    
    //остановить рекурсивное прохождение при достижении пустого дерева
    if (t == nullptr)
        return nullptr;
    // CopyTree строит новое дерево в процессе прохождения узлов дерева t
    // ф-ия CopyTree проверяет наличие сыновей сначала влево потом вправо
    //после проверки создает копию и подвешивет к дереву копии сыновей
    if (t->Left() != nullptr)
        newlptr = CopyTree(t->Left());
    else
        newlptr = nullptr;

    if (t->Right() != nullptr)
        newrptr = CopyTree(t->Right());
    else
        newrptr = nullptr;
    //построить новое дерево снизу верх
    //сначала создавая двух сыновей, а затем их родителя
    newnode = GetTreeNode(t->data, newlptr, newrptr);

    //вернуть указатель на новое созданное дерево
    return newnode;
}