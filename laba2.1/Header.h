#pragma once
//#include <iostream>
//��������������� �������� ������ ��������� ������ ������

template <class T>
class BinSTree;

//����������� ������ ����� ��������� ������
template <class T>
class TreeNode

{
    //��������� �� ����� � ������ ����������� ����

    TreeNode<T>* left;

    TreeNode<T>* right;

public:
    //�������� ������� ������ ������, ����������� ����������

    T data;

    //�����������: �������������� ���� ������ � ���������

    //�� ����������� ����

    TreeNode(const T& item, TreeNode<T>* lptr = NULL, TreeNode<T>* rptr = NULL);

    //TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr) :
    //
    //   data(item), left(lptr), right(rptr) { }

    // ������ ������� � ���������� �� ����������� ����

    TreeNode<T>* Left(void) const;

    TreeNode<T>* Right(void) const;

    // �������� ������ BinSTree ��� ��������������

    friend class BinSTree<T>;

};

//������� ������ TreeNode � ������������� ������ lptr � rptr.

//�� ��������� ��������� �������� NULL.

template <class T>

TreeNode<T>::TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr) :
    
    data(item), left(lptr), right(rptr) { }

template <class T>

TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = NULL,

    TreeNode<T>* rptr = NULL)
{
    TreeNode<T>* p;
    //������� new ��� �������� ������ ����
    //�������� ���� ��������� lptr � rptr
    p = new TreeNode<T>(item, lptr, rptr);
    //���� ������ ������������, ���������
    //��������� ���������� �� ������
    if (p == NULL)
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