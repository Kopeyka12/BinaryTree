#include "pch.h"
#include "C:\Users\Влад\Desktop\Учеба\УЧЁБА\2 курс\4 семестр\САОД\laba2.1\laba2.1\treelib.h"
#include "C:\Users\Влад\Desktop\Учеба\УЧЁБА\2 курс\4 семестр\САОД\laba2.1\laba2.1\treenode.h"
#include <cassert>
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

    // ñîçäà¸òñÿ óêàçàòåëè íà óçëû äåðåâà 
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

    // ñîçäà¸òñÿ óêàçàòåëè íà óçëû äåðåâà 
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
    // V = 1 3 4 6 7 8 10 13 14 
    //       3
    //        \
    //         8
    //          \
    //           50
    //            \
    //             38


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

    std::vector <int> v3;
    vactornode(root3, v3);
    assert(V3 == v3);
}


TEST(TestTreeNode, TestVector) {
    TreeNode<int>* root1 = createTree1();
    const std::vector <int> V1{ 1,3,4,6,7,8,10,13,14 };

    std::vector <int> v1;
    vactornode(root1, v1);
    assert(V1 == v1);

    TreeNode<int>* root2 = createTree2();
    const std::vector <int> V2{ 3,8,50,38 };

    std::vector <int> v2;
    vactornode(root2, v2);
    assert(V2 == v2);

    TreeNode<int>* root3 = createTree3();
    const std::vector <int> V3{ 6,9,38,4,50 };

    std::vector <int> v3;
    vactornode(root3, v3);
    assert(V3 == v3);
}
/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}*/