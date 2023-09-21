#pragma once
#include <iostream>
//����������� ����������� ����������� ����� ������  LNR
template <class T>
void Inorder(TreeNode<T>* t, void visit(T& item)) {

    //����������� ����������� ����������� �� ������ ���������

    if (t != nullptr) {

        Inorder(t->Left(), visit);      //���������� �� ������ ���������

        visit(t->data);                 //�������� ����

        Inorder(t->Right(), visit);     //���������� �� ������� ���������
    }
}

//�-�� ������ LRN
template <class T>
void Postorder(TreeNode<T>* t) {

    //����������� ����������� ����������� �� ������ ���������

    if (t != nullptr) {

        Postorder(t->Left());      //���������� �� ������ ���������

        Postorder(t->Right());     //���������� �� ������� ���������

        std::cout << t->data << " ";                 //�������� ����
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



//��-�� LRN
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
