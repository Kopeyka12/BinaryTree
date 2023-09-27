#pragma once
#include <iostream>
#include <queue>
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
//�-�� ������ �������� ����
template <class T>
void visit_print(T& item) {
    std::cout << item << " ";
}
//�-�� ����������� �������� ���� �� 1
template <class T>
void visit_inc(T& item) {
    item++;
}

//���������� �������� ����� �����������.
//�� ����� ��������� ���� �����������, �������� �� �� ��������
template <class T>
int CountLeaf(TreeNode<T>* t, int& count) {
    
    //�������� ����� �����������
    if (t != nullptr)
    {
        CountLeaf(t->Left(), count);    //������ ����� ���������
        CountLeaf(t->Right(), count);   //������ ������ ���������
        
        //���������, �������� �� ������ ���� ������
        //���� ��, �� ������������ count
        if (t->Left() == nullptr && t->Right() == nullptr)
            count++;
    }
    return count;
}



//��-�� LRN
//��������� ������� ������ ����� �������
// 1+ max(depthLeft, depthRight)
//������� ������� ������ ����� -1
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


//���������� �/� ��������
const int indentBlock = 4;
//�������� num �������� �� ������� ������
void IndentBlocks(int num)
{
    for (int i = 0; i < num; i++)
        std::cout << " ";
}
//����������� ������ �����, ��������� RNL-�����������
template <class T>
void PrintTree(TreeNode<T>* t, int level)
{
    //�������� ������ � ������ t ���� ������ �� ������
    if (t != nullptr) 
    {
        PrintTree(t->Right(), level + 1);   //�������� ������ ��������� ���� 
        IndentBlocks(indentBlock * level);  //��������� ������� ������� � ������� ���� ������
        std::cout << t->data << std::endl;  
        PrintTree(t->Left(), level + 1);    //������ ������ ���������
    }
}

//������� �������� ������ t � ���������� ������ ������ ������
template<class T>
TreeNode<T>* CopyTree(TreeNode<T>* t) {
    //newnode ��������� �� ����� ����, �����������
    //����������� ������ GetTreeNode � ��������������� ������ ������
    //���������� newlptr, newrptr 

    TreeNode<T>* newlptr, * newrptr, * newnode;
    
    //���������� ����������� ����������� ��� ���������� ������� ������
    if (t == nullptr)
        return nullptr;
    // CopyTree ������ ����� ������ � �������� ����������� ����� ������ t
    // �-�� CopyTree ��������� ������� ������� ������� ����� ����� ������
    //����� �������� ������� ����� � ���������� � ������ ����� �������
    if (t->Left() != nullptr)
        newlptr = CopyTree(t->Left());
    else
        newlptr = nullptr;

    if (t->Right() != nullptr)
        newrptr = CopyTree(t->Right());
    else
        newrptr = nullptr;
    //��������� ����� ������ ����� ����
    //������� �������� ���� �������, � ����� �� ��������
    newnode = GetTreeNode(t->data, newlptr, newrptr);

    //������� ��������� �� ����� ��������� ������
    return newnode;
}