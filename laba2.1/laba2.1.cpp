﻿// lab 2.1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//@avtor Мирошин В. И.
//Основная программа
#include <iostream>
#include "treelib.h"
#include "treenode.h"
#include "binstree.h"
#include <queue>
#include <vector>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    //создаётся указатели на узлы дерева 
    TreeNode<int>* leftleaf, * rightleaf, * root, *root1, *root2;
    //создание дерева 
    root = new TreeNode<int>(10);
    root->right = new TreeNode<int>(12);
    root->right->right = new TreeNode<int>(5);
    root->right->left= new TreeNode<int>(4);
    root->right->left->left = new TreeNode<int>(2);

    //      10
    //        \
    //         5
    //        / \
    //       2   4
    //      /
    //     12

    cout <<"Вывод дерева: " << endl;
    PrintTree(root, 0);
    
    cout << "Обход дерева по принципу LNR: " << endl;
    Inorder(root,visit_print);  //обход дерева и вывод узлов
    std::cout << std::endl;

    std::cout <<"Обход дерева по принципу LRN: " << std::endl;
    Postorder(root);
    std::cout << std::endl;

    cout << "Обход дерева в ширине: " << endl;
    LevelScan(root, visit_print);
    
    int leafCount = 0;
    CountLeaf(root, leafCount);
    cout << endl<<"Число листьев = " << leafCount << endl;
    cout << "Глубина дерева равна = " << Depth(root) << endl;

    cout << endl << "Копия:" << endl;
    root1 = CopyTree(root);
    AddNode(root, 20);
    PrintTree(root1, 0);

    cout << "\nНахождение следующего наибольшего для 10: ";
    TreeNode<int>* s = nullptr;

    Successor(root, s, 10);
    if (s != nullptr) {
        cout << s->data;
    }
    else cout << "Не существует\n";

    cout << endl << "Преобразование Дерева в vector:" << endl;
    std::vector<int> vec, v;
    vactornode(root, vec);
    
    for (int i = 0; i < vec.size(); i++) {
       std::cout << vec.at(i) << ' ';
    }
    
    root = DeleteNode(root, 12);
    cout << endl<<"Выводим дерево после удалении узла 12" << endl;
    Inorder(root, visit_print);  //обход дерева и вывод узлов
    cout << endl;
    PrintTree(root, 0);

    BinSTree<int> T;
    T.Insert(40);
    T.Insert(70);
    T.Insert(45);
    T.Insert(35);
     
    for (BinSTree<int>::BinSTreeIterator<int> it1 = T.begin(); it1 != T.end(); ++it1) {
        cout << *it1 << " ";
    }

    root2 = new TreeNode<int>(8);
    root2->right = new TreeNode<int>(10);
    root2->right->right = new TreeNode<int>(14);
    root2->right->right->left = new TreeNode<int>(13);
    root2->left = new TreeNode<int>(3);
    root2->left->left = new TreeNode<int>(1);
    root2->left->right = new TreeNode<int>(6);
    root2->left->right->right = new TreeNode<int>(7);
    root2->left->right->left = new TreeNode<int>(4);
    BinSTree<int> b(root2);
    b.Delete(6);
    b.treevactor(v);
    
    cout << endl << "Бинарное дерево:" << endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << ' ';
    }
    
    
   
    
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
