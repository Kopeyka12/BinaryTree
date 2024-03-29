//@avtor ������� �. �.
//������� ��� ������ � ��������� 
#pragma once
#include <iostream>
#include <queue>
//����������� ����������� ����������� ����� ������  LNR
//visit ��������-������� ������� ������� ������ �� ���� ������
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
    newnode = new TreeNode<T>(t->Data(), newlptr, newrptr);

    //������� ��������� �� ����� ��������� ������
    return newnode;
}

//����� ������ �� ������
//visit ��������-������� ������� ������� ������ �� ���� ������
template<class T>
void LevelScan(TreeNode<T>* t, void visit (T& item))
{
    std::queue<TreeNode<T> *> Q;
    Q.push(t);
    while (!Q.empty())
    {
        TreeNode<T>* p;
        p = Q.front();
        Q.pop();
        visit(p->data);
        
        if (p->Left() != nullptr)
            Q.push(p->Left());
        if (p->Right() != nullptr)
            Q.push(p->Right());
    }
}

//���������� ���� � ������
template<class T>
TreeNode<T>* AddNode(TreeNode<T>* node, const T& item)
{
    //���� ���� ����� nullptr �� ��������� ������ � ������ �������� item
    if (node == nullptr) {
        return new TreeNode<int>(item, nullptr, nullptr);
    }
    //���� ���� �� ������
    if (node!=nullptr)
    {
        //���� ���� ������� ������ �������� ������ ������� ����
        if (item < node->data)
            node->left = AddNode(node->left, item); //���� ����� � ��� ��������� ������� 
        else
            node->right = AddNode(node->right, item);//����� ���� ������ � ��� ��������� �������
    }
    
    return node;
}

//�������������� ������ � ������
template< typename T >
void vactornode(TreeNode<T>* root, std::vector<T>& vec) {
    if (root != nullptr) {
        vactornode(root->left, vec);
        vec.push_back(root->data);
        vactornode(root->right, vec);
    }
}
//����� ���� � ������
template <typename T>
int SearchNode(TreeNode<T>* root, const T key, int depth = 0) {
    // ���� ����� �� nullptr, �� �������� �������� � ������ ���
    if (root == nullptr) {
        return -1;
    }

    // ����� � ������ ���������
    if (key > root->Data()) {
        SearchNode(root->Right(), key, depth + 1);
    }

    // ����� � ����� ���������
    else if (key < root->Data()) {
        SearchNode(root->Left(), key, depth + 1);
    }

    // ���� key ����� �������� � ������� ����
    else return depth;
}