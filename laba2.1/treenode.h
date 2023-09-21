#pragma once
#include <iostream>
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

template <class T>
void visit_print(T& item) {
    std::cout << item << " ";
}

template <class T>
void visit_inc(T& item) {
    item++;
}


template <class T>
int CountLeaf(TreeNode<T>* t, int& count) {

    if (t != nullptr)
    {

        CountLeaf(t->Left(), count);

        CountLeaf(t->Right(), count);

        if (t->Left() == nullptr && t->Right() == nullptr)

            count++;
    }
    return count;
}



//фу-ия LRN
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
