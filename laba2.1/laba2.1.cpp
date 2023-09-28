﻿// lab 2.1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "treelib.h"
#include "treenode.h"
#include "binstree.h"
#include <queue>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    //создаётся указатели на узлы дерева 
    TreeNode<int>* leftleaf, * rightleaf, * root, *root1;
    //создание дерева 
    root = new TreeNode<int>(10);

    root->right = new TreeNode<int>(5);

    root->right->right = new TreeNode<int>(4);

    root->right->left= new TreeNode<int>(2);

    root->right->left->left = new TreeNode<int>(12);

    //      10
    //        \
    //         5
    //        / \
    //       2   4
    //      /
    //     12


    cout << "Обход дерева по принципу LNR: " << endl;
    //Inorder(root, visit_inc);  //обход дерева с увеличнием значений узла
    Inorder(root,visit_print);  //обход дерева и вывод узлов
    std::cout << std::endl;
    
    std::cout <<"Обход дерева по принципу LRN: " << std::endl;
    Postorder(root);
    std::cout << std::endl;
    
    int leafCount = 0;
    CountLeaf(root, leafCount);
    cout << "Число листьев = " << leafCount << endl;
    
    cout << "Глубина дерева равна = " << Depth(root) << endl;
    cout <<"Вывод дерева: " << endl;
    PrintTree(root, 0);
    //AddNode(root, 20);
    
    cout << "Обход дерева в ширине: " << endl;
    LevelScan(root, visit_print);

    cout << endl << "Копия:" << endl;
    root1 = CopyTree(root);
    Postorder(root1);
    cout << endl;
    PrintTree(root1, 0);
    
    BinSTree<int> T;
    T.Insert(40);
    T.Insert(70);
    T.Insert(45);
    T.Insert(35);
    //cout << endl << "Дерево BST:" << endl;
    


}

//todo: посчет узлов(3), вставка(2), удаление дерева, поиск(1)



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
