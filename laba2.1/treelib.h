#pragma once
//��������������� �������� ������ ��������� ������ ������

template <class T>
class BinSTree;

//����������� ������ ����� ��������� ������
template <class T>
class TreeNode

{
private:
    

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
void FreeTreeNode(TreeNode<T>* p) {delete p;}


