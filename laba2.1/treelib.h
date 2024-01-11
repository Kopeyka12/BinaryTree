#pragma once
#include <cassert>
//#include <TestTreeNode.cpp>
//��������������� �������� ������ ��������� ������ ������

template <class T>
class BinSTree;

//����������� ������ ����� ��������� ������
template <class T>
class TreeNode

{
public:
    //��������� �� ����� � ������ ����������� ����
    TreeNode<T> *left;
    TreeNode<T> *right;

    //�������� ������� ������ ������, ����������� ����������
    T data;

    //�����������: �������������� ���� ������ � ���������
    //�� ����������� ����
    TreeNode(const T& item, TreeNode<T>* lptr = nullptr, TreeNode<T>* rptr = nullptr);    

    // ������ ������� � ���������� �� ����������� ����
    TreeNode<T>* Left() const;
    TreeNode<T>* Right() const;
    T Data() const;
    void SetData(T data1);

    void SetRight(TreeNode<T>* right1);

    void SetLeft(TreeNode<T>* left1);

    // �������� ������ BinSTree ��� ��������������
    friend class BinSTree<T>;
};

//������� ������ TreeNode � ������������� ������ lptr � rptr.
//�� ��������� ��������� �������� NULL.

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

// ����� ������� �������� ���� ������
template <typename T>
void TreeNode<T>::SetData(T data1) {
    this->data = data1;
}


// ����� ������� �������� ������� �������
template <typename T>
void TreeNode<T>::SetRight(TreeNode<T>* right1) {
    this->right = right1;
}

// ����� ������� �������� ������ �������
template <typename T>
void TreeNode<T>::SetLeft(TreeNode<T>* left1) {
    this->left = left1;
}

// ����� Data ���������� �������� ���� ������
template <typename T>
T TreeNode<T>::Data() const
{
    return this->data;
}

//������� ������ TreeNode � ������������� ������ lptr � rptr
//�� ��������� ��������� nullptr
template <class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,

    TreeNode<T>* rptr = nullptr)//
{
    TreeNode<T>* p;
    //������� new ��� �������� ������ ����
    //�������� ���� ��������� lptr � rptr
    p = new TreeNode<T>(item, lptr, rptr);

    //���� ������ ������������, ���������
    //��������� ���������� �� ������
    if (p == nullptr)
    {
        std::cerr << "������ ��� ��������� ������!\n";
        
        exit(1);
    }
    //������� ��������� �� ���������� �������� ������
    return p;
}

//���������� ������������ ������, ���������� ������ �����
template <class T>
void FreeTreeNode(TreeNode<T>* p)
{
    delete p;
}

//���������� �������� ��������� ����������� 
//������� ������ ���� ��� ��� ���������
template <class T>
void DeleteTree(TreeNode<T>* t)
{
    if (t != nullptr) {
        DeleteTree(t->Left());
        DeleteTree(t->Right());
        FreeTreeNode(t);
    }
}

//�������� �-�� ��� �������� ����� ������
//����� ���������� ��������� �� ��� ������ � nullptr
template <class T>
void ClearTree(TreeNode<T>& t)
{
    DeleteTree(t);
    t = nullptr;
}

// ���������� ������������ ���� � ���������
template <typename T>
TreeNode<T>* getNextLeft(TreeNode<T>* root)
{
    while (root->Left() != nullptr) {
        root = root->Left();
    }

    return root;
}

// ���������� ���������� �����������
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

    // ������� ������ (������ ������)
    if (root == nullptr) {
        succ = nullptr;
    }

    // ���� ������ ����, ��� �������� ����� ����� ��������� ����������
    else if (root->data == key)
    {
        // ���� ���� ������ �������
        if (root->Right() != nullptr) {
            // ������� ����� ����� ���� �� ������� �������
            succ = getNextLeft(root->Right());
        }
    }

    // ����� ������� ���� � ����� ��� ������ ���������
    else if (key < root->data)
    {
        succ = root;
        Successor(root->Left(), succ, key);
    }
    else {
        Successor(root->Right(), succ, key);
    }
}


// ����������� ����� ��� �������� ���� �� ������
template <typename T>
TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {

    // ������� ������
    if (root == nullptr) {
        return root;
    }

    // ����������� ����� �������, ���� �� ����� ������ ����, ������� ����� �������
    if (root->Data() > value) {
        root->SetLeft(DeleteNode(root->Left(), value));
        return root;
    }
    else if (root->Data() < value) {
        root->SetRight(DeleteNode(root->Right(), value));
        return root;
    }

    // ����� ������ ���� �� ��������

    // ������ 1 � 2. ���� ���� ������ 1 ������� ��� ������� ���������� ���� (0 ��������)
    // ���� ��� ������ �������, �� ������ ����������� �� ����� ���������� ����
    if (root->Left() == nullptr) {
        TreeNode<T>* temp = root->Right();
        delete root;
        return temp;
    }
    // ���� ��� ������� �������, �� ����� ����������� �� ����� ���������� ����
    else if (root->Right() == nullptr) {
        TreeNode<T>* temp = root->Left();
        delete root;
        return temp;
    }

    // ������ 3. ���� ���� ��� �������
    else {

        // ����, ������� �������� ��������� ���������� �����������
        TreeNode<T>* succParent = root;

        // ������� ��������� ���������� (����� ����� ���� � ������ ���������) � ��� ��������
        TreeNode<T>* succ = root->Right();
        while (succ->Left() != nullptr) {
            succParent = succ;
            succ = succ->Left();
        }


        // ������ �������� � ������ �������� ���� ������ � ������ ��������
        // ������� ������� ���������� ����������� ������ ����� �������� ��������
        // ���������� �����������

        if (succParent != root)
            succParent->SetLeft(succ->Right());
        else
            // ���� ������ �� ������ ��������� �� ����
            succParent->SetRight(succ->Right());


        // ������ �� ���������� ����������� ����������� �� ����� ���������� ����
        root->SetData(succ->Data());

        // ������� ��������� ����������
        delete succ;
        return root;
    }
    
    
    //if (root == nullptr) {
    //    return root;
    //}

    //// ���� �������� ����� ������ �������� ��������� ����, ���������� ���� ���� � ����� ���������
    //if (key < root->data) {
    //    root->left = DeleteNode(root->left, key);
    //}
    //// ���� �������� ����� ������ �������� ��������� ����, ���������� ���� ���� � ������ ���������
    //else if (key > root->data) {
    //    root->right = DeleteNode(root->right, key);
    //}
    //// ���� �������� ����� ����� �������� ��������� ����, �� ��� ����, ������� ����� �������
    //else {
    //    // ���� � ���� ��� �������� ��� ������ ���� �������, �� ������ ������� ����, ������� ��� �� ���������������� �������
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

    //    // ���� � ���� ���� ��� �������, �� ������� ���������� ���� � ������ ��������� (��� ���������� � ����� ���������)
    //    // � �������� ������� ���� �� ��������� ����, � ����� ������� ��������� ����
    //    TreeNode<T>* temp = root->right;
    //    while (temp->left != nullptr) {
    //        temp = temp->left;
    //    }

    //    root->data = temp->data;
    //    root->right = DeleteNode(root->right, temp->data);
    //}

    //return root;
}