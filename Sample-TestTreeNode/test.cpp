#include "pch.h"
#include "C:\Users\Влад\Desktop\Учеба\УЧЁБА\2 курс\4 семестр\САОД\laba2.1\laba2.1\treelib.h"
#include "C:\Users\Влад\Desktop\Учеба\УЧЁБА\2 курс\4 семестр\САОД\laba2.1\laba2.1\treenode.h"
#include "C:\Users\Влад\Desktop\Учеба\УЧЁБА\2 курс\4 семестр\САОД\laba2.1\laba2.1\binstree.h"
#include <cassert>
#include <sstream>
TreeNode<int>* createTree1() {

    //        8
    //     /    \
    //    3      10
    //   / \      \
    //  1   6      14
    //     / \     /
    //    4   7  13



    //создаётся указатели на узлы дерева 
    TreeNode<int>* leftleaf, * rightleaf, * root;
    //создание дерева 
    root = new TreeNode<int>(8);
    root->right = new TreeNode<int>(10);
    root->right->right = new TreeNode<int>(14);
    root->right->right->left = new TreeNode<int>(13);
    root->left = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(6);
    root->left->right->right = new TreeNode<int>(7);
    root->left->right->left = new TreeNode<int>(4);

    return root;
}

TreeNode<int>* createTree2() {

    //создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, * root;


    //       3
    //        \
    //         8
    //          \
    //           50
    //            \
    //             38

    root= new TreeNode<int>(3);
    root->right = new TreeNode<int>(8);
    root->right->right = new TreeNode<int>(50);
    root->right->right->right = new TreeNode<int>(38);
    return root;
}


TreeNode<int>* createTree3() {

    //создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, * root;


    //       6
    //        \
    //         9
    //          \
    //           50
    //          /  
    //         38
    //           \
    //            4
    
    root = new TreeNode<int>(6);
    root->right = new TreeNode<int>(9);
    root->right->right = new TreeNode<int>(50);
    root->right->right->left = new TreeNode<int>(38);
    root->right->right->left->right = new TreeNode<int>(4);
    return root;
}

BinSTree<int> createBST1() {
    BinSTree<int> T;
    T.Insert(20);
    T.Insert(1);
    T.Insert(73);
    T.Insert(15);
    T.Insert(65);
    T.Insert(34);
    T.Insert(10);
    return T;
}

TEST(TestTreeNode, TestVector) {
    TreeNode<int>* root1 = createTree1();
    const std::vector <int> V1 {1,3,4,6,7,8,10,13,14};
    
    std::vector <int> v1;
    vactornode(root1, v1);
    assert(V1 == v1);

    TreeNode<int>* root2 = createTree2();
    const std::vector <int> V2 {3,8,50,38};

    std::vector <int> v2;
    vactornode(root2, v2);
    assert(V2 == v2);
    
    TreeNode<int>* root3 = createTree3();
    const std::vector <int> V3{6,9,38,4,50};
    //LNR
    std::vector <int> v3;
    vactornode(root3, v3);
    assert(V3 == v3);
}
//ф-ия обхода LRN
TEST(TestTreeNode, TestPostorder) {
    TreeNode <int>* root4 = createTree1();

    //Класс stringstream позволяет рассматривать строковый объект как поток. Он используется для работы со строками.
    //Рассматривая строки как потоки, мы можем выполнять операции извлечения и вставки из/в строку так же, как потоки cin и cout.
    std::ostringstream oss;
    //Класс streambuf обеспечивает буферизацию данных во всех производных классах,
    //которыми явно или неявно пользуется программист.
    //rdbuf() позволяет нескольким объектам потоков данных читать из одного входного канала или записывать в один выходной канал без нарушения порядка ввода - вывода
    std::streambuf* p_cout_streambuf = std::cout.rdbuf(); //p_cout_streambuf имеет значение откуда считывать строку 
    std::cout.rdbuf(oss.rdbuf());//рассматриваем строку как поток для дальнейшего извлечения.
    
    Postorder(root4);//вызываем метод в котором значение сразу выводиться в консоль

    std::cout.rdbuf(p_cout_streambuf); 

    // тестируем наш метод
    assert(oss.str() == "1 4 7 6 3 13 14 10 8 ");
}

TEST(TestTreeNode, TestDepth) {
    TreeNode <int>* root1 = createTree1();
    assert(Depth(root1)==3);

    TreeNode <int>* root2 = createTree2();
    assert(Depth(root2) == 3);

    TreeNode <int>* root3 = createTree3();
    assert(Depth(root3) == 4);
}

TEST(TestTreeNode, TestCountLeaf) {
    int leafCount = 0;
    TreeNode <int>* root1 = createTree1();
    assert(CountLeaf(root1, leafCount) == 4);
    leafCount = 0;
    TreeNode <int>* root2 = createTree2();
    assert(CountLeaf(root2, leafCount) == 1);
    leafCount = 0;
    TreeNode <int>* root3 = createTree3();
    assert(CountLeaf(root3, leafCount) == 1);
}

TEST(TestTreeNode, TestLevelScan) {
    TreeNode <int>* root6 = createTree1();

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf(); 
    std::cout.rdbuf(oss.rdbuf());

    LevelScan(root6,visit_print);

    std::cout.rdbuf(p_cout_streambuf);

    // тестируем наш метод
    assert(oss.str() == "8 3 10 1 6 14 4 7 13 ");


    TreeNode <int>* root7 = createTree2();

    std::ostringstream oss2;
    std::streambuf* p_cout_streambuf2 = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());

    LevelScan(root7, visit_print);

    std::cout.rdbuf(p_cout_streambuf2);

    // тестируем наш метод
    assert(oss2.str() == "3 8 50 38 ");


    TreeNode <int>* root8 = createTree3();

    std::ostringstream oss3;
    std::streambuf* p_cout_streambuf3 = std::cout.rdbuf();
    std::cout.rdbuf(oss3.rdbuf());

    LevelScan(root8, visit_print);

    std::cout.rdbuf(p_cout_streambuf3);

    // тестируем наш метод
    assert(oss3.str() == "6 9 50 38 4 ");
}

TEST(TestBST, TestVectorBST_Test) {
    BinSTree<int> E = createBST1();
    /*std::vector<int> v1, V1;

    const std::vector <int> V3{ 1,10,15,20,34,65,73 };
    E.treevactor(v1);
    assert(V1 == v1);*/
    assert(2 == 2);
}