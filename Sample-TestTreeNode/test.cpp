#include "pch.h"
#include "C:\Users\Влад\Desktop\Учеба\УЧЁБА\2 курс\4 семестр\САОД\laba2.1\laba2.1\treelib.h"//исправить путь
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

TreeNode<int>* createTree4() {

    //создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, * root;

        //     8
        //    / \
        //   3   10
        //  / \
        // 1   6
        //    /
        //   4

    root = new TreeNode<int>(8);
    root->right = new TreeNode<int>(10);
    root->left = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(6);
    root->left->right->left = new TreeNode<int>(4);

    return root;
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
//ф-ия обхода LRN
TEST(TestTreeNode, TestDeleteNode) {
    TreeNode <int>* root10 = createTree4();
    root10 = DeleteNode(root10, 3);
    //Класс stringstream позволяет рассматривать строковый объект как поток. Он используется для работы со строками.
    //Рассматривая строки как потоки, мы можем выполнять операции извлечения и вставки из/в строку так же, как потоки cin и cout.
    std::ostringstream oss;
    //Класс streambuf обеспечивает буферизацию данных во всех производных классах,
    //которыми явно или неявно пользуется программист.
    //rdbuf() позволяет нескольким объектам потоков данных читать из одного входного канала или записывать в один выходной канал без нарушения порядка ввода - вывода
    std::streambuf* p_cout_streambuf = std::cout.rdbuf(); //p_cout_streambuf имеет значение откуда считывать строку 
    std::cout.rdbuf(oss.rdbuf());//рассматриваем строку как поток для дальнейшего извлечения.

    Inorder(root10, visit_print);//вызываем метод в котором значение сразу выводиться в консоль

    std::cout.rdbuf(p_cout_streambuf);

    // тестируем наш метод
    assert(oss.str() == "1 4 6 8 10 ");
}

TreeNode<int>* createTreeBST() {

    //создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, * root;


    //       3
    //        \
    //         8
    //          \
    //           38
    //            \
    //             50

    root = new TreeNode<int>(3);
    root->right = new TreeNode<int>(8);
    root->right->right = new TreeNode<int>(38);
    root->right->right->right = new TreeNode<int>(50);
    return root;
}

TreeNode<int>* createTreeBST2() {

    //создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, * root;


    //       4
    //      / \
    //     6   38
    //    /     \
    //   9       50

    root = new TreeNode<int>(9);
    root->left = new TreeNode<int>(6);
    root->left->left = new TreeNode<int>(4);
    root->right = new TreeNode<int>(38);
    root->right->right = new TreeNode<int>(50);
    return root;
}

TreeNode<int>* createTreeBST3() {

    //создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, * root;

        //     8
        //    / \
        //   3   10
        //  / \
        // 1   6
        //    /
        //   4

    root = new TreeNode<int>(8);
    root->right = new TreeNode<int>(10);
    root->left = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(6);
    root->left->right->left = new TreeNode<int>(4);

    return root;
}

TEST(TestBST, TestInsertBST_Test) {
    BinSTree<int> tr1(createTree1());
    std::vector<int> v;
    std::ostringstream oss;
    
    tr1.Insert(2);
    tr1.treevactor(v);
    
    std::streambuf* p_cout_streambuf = std::cout.rdbuf(); 
    std::cout.rdbuf(oss.rdbuf());
   
    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << ' ';
    }

    std::cout.rdbuf(p_cout_streambuf);
    assert(oss.str() == "1 2 3 4 6 7 8 10 13 14 ");


    BinSTree<int> tr2(createTreeBST());
    std::vector<int> v2;
    std::ostringstream oss2;
    
    tr2.Insert(5);
    tr2.treevactor(v2);

    std::streambuf* p_cout_streambuf2 = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());

    for (int i = 0; i < v2.size(); i++) {
        std::cout << v2.at(i) << ' ';
    }

    std::cout.rdbuf(p_cout_streambuf2);
    assert(oss2.str() == "3 5 8 38 50 ");


    BinSTree<int> tr3(createTreeBST2());
    std::vector<int> v3;
    std::ostringstream oss3;

    tr3.Insert(40);
    tr3.treevactor(v3);

    std::streambuf* p_cout_streambuf3 = std::cout.rdbuf();
    std::cout.rdbuf(oss3.rdbuf());

    for (int i = 0; i < v3.size(); i++) {
        std::cout << v3.at(i) << ' ';
    }

    std::cout.rdbuf(p_cout_streambuf3);
    assert(oss3.str() == "4 6 9 38 40 50 ");

    BinSTree<int> tr4(createTreeBST3());
    std::vector<int> v4;
    std::ostringstream oss4;

    tr4.Insert(22);
    tr4.treevactor(v4);

    std::streambuf* p_cout_streambuf4 = std::cout.rdbuf();
    std::cout.rdbuf(oss4.rdbuf());

    for (int i = 0; i < v4.size(); i++) {
        std::cout << v4.at(i) << ' ';
    }

    std::cout.rdbuf(p_cout_streambuf4);
    assert(oss4.str() == "1 3 4 6 8 10 22 ");
}


TEST(TestBST, TestFind_Test) {

    BinSTree<int> tr1(createTreeBST());
    int l1 = tr1.Find(38);
    int l2 = tr1.Find(15);

    assert(l1 == 2);
    assert(l2 == -1);

    BinSTree<int> tr2(createTreeBST2());
    l1 = tr2.Find(9);
    l2 = tr2.Find(100);

    assert(l1 == 0);
    assert(l2 == -1);
    
    BinSTree<int> tr3(createTreeBST3());
    l1 = tr3.Find(8);
    l2 = tr3.Find(15);

    assert(l1 == 0);
    assert(l2 == -1);
}

TEST(TestBST, TestDelete_Test) {
    BinSTree<int> tr1(createTree1());
    std::vector<int> v;
    std::ostringstream oss;

    tr1.Delete(6);
    tr1.treevactor(v);

    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << ' ';
    }

    std::cout.rdbuf(p_cout_streambuf);
    assert(oss.str() == "1 3 4 7 8 10 13 14 ");

    BinSTree<int> tr2(createTreeBST());
    std::vector<int> v2;
    std::ostringstream oss2;

    tr2.Delete(50);
    tr2.treevactor(v2);

    std::streambuf* p_cout_streambuf2 = std::cout.rdbuf();
    std::cout.rdbuf(oss2.rdbuf());

    for (int i = 0; i < v2.size(); i++) {
        std::cout << v2.at(i) << ' ';
    }

    std::cout.rdbuf(p_cout_streambuf2);
    assert(oss2.str() == "3 8 38 ");


    BinSTree<int> tr3(createTreeBST2());
    std::vector<int> v3;
    std::ostringstream oss3;

    tr3.Delete(4);
    tr3.treevactor(v3);

    std::streambuf* p_cout_streambuf3 = std::cout.rdbuf();
    std::cout.rdbuf(oss3.rdbuf());

    for (int i = 0; i < v3.size(); i++) {
        std::cout << v3.at(i) << ' ';
    }

    std::cout.rdbuf(p_cout_streambuf3);
    assert(oss3.str() == "6 9 38 50 ");

    BinSTree<int> tr4(createTreeBST3());
    std::vector<int> v4;
    std::ostringstream oss4;

    tr4.Delete(8);
    tr4.treevactor(v4);

    std::streambuf* p_cout_streambuf4 = std::cout.rdbuf();
    std::cout.rdbuf(oss4.rdbuf());

    for (int i = 0; i < v4.size(); i++) {
        std::cout << v4.at(i) << ' ';
    }

    std::cout.rdbuf(p_cout_streambuf4);
    assert(oss4.str() == "1 3 4 6 10 ");
}