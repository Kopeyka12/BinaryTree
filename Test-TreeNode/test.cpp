#include "pch.h"
#include "C:\Users\Влад\Desktop\Учеба\УЧЁБА\2 курс\4 семестр\САОД\laba2.1\laba2.1\treelib.h"

TreeNode<int>* createTree1() {

    // ñîçäà¸òñÿ óêàçàòåëè íà óçëû äåðåâà 
    TreeNode<int>* leftleaf, * rightleaf, * root;


    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    //ñîçäà¸òñÿ óêàçàòåëü íà ëèñò äåðåâà (óêàçàòåëè íà ëåâûé è ïðàâûé óçëû nullptr)
    leftleaf = new TreeNode<int>(10);

    //ñîçäà¸òñÿ óçåë òîëüêî ñ ëåâûì ïîòîìêîì
    root = new TreeNode<int>(12, leftleaf, nullptr);

    // óêàçàòåëü leftleaf ïåðåíîñèòñÿ íà òîëüêî ÷òî ñîçäàííûé óçåë
    leftleaf = root;
    rightleaf = new TreeNode<int>(24);

    //ñîçäà¸òñÿ óçåë ñ ëåâûì è ïðàâûì ïîòîìêîì
    root = new TreeNode<int>(22, leftleaf, rightleaf);
    rightleaf = root;
    leftleaf = new TreeNode<int>(4);

    //ñîçäà¸òñÿ óçåë òîëüêî ñ ïðàâûì ïîòîìêîì
    root = new TreeNode<int>(5, leftleaf, rightleaf);

    return root;
}

// âûðîæäåííîå âïðàâî
TreeNode<int>* createTree2() {

    // ñîçäà¸òñÿ óêàçàòåëè íà óçëû äåðåâà 
    TreeNode<int>* rightleaf, * root;


    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

    //ñîçäà¸òñÿ óêàçàòåëü íà ëèñò äåðåâà (óêàçàòåëè íà ëåâûé è ïðàâûé óçëû nullptr)
    rightleaf = new TreeNode<int>(33);

    //ñîçäà¸òñÿ óçåë òîëüêî ñ ïðàâûì ïîòîìêîì
    root = new TreeNode<int>(30, nullptr, rightleaf);

    // óêàçàòåëü rightleaf ïåðåíîñèòñÿ íà òîëüêî ÷òî ñîçäàííûé óçåë
    rightleaf = root;

    //ñîçäà¸òñÿ óçåë ñ ïðàâûì ïîòîìêîì
    root = new TreeNode<int>(19, nullptr, rightleaf);
    rightleaf = root;

    //ñîçäà¸òñÿ óçåë òîëüêî ñ ïðàâûì ïîòîìêîì
    root = new TreeNode<int>(10, nullptr, rightleaf);

    return root;
}

// âûðîæäåííîå âëåâî
TreeNode<int>* createTree3() {

    // ñîçäà¸òñÿ óêàçàòåëè íà óçëû äåðåâà 
    TreeNode<int>* leftleaf, * root;


    //       60
    //       /  
    //      54   
    //      /   
    //     14      



    //ñîçäà¸òñÿ óçåë
    root = new TreeNode<int>(14);

    // óêàçàòåëü rightleaf ïåðåíîñèòñÿ íà òîëüêî ÷òî ñîçäàííûé óçåë
    leftleaf = root;

    //ñîçäà¸òñÿ óçåë ñ ëåâûì ïîòîìêîì
    root = new TreeNode<int>(54, leftleaf, nullptr);
    leftleaf = root;

    //ñîçäà¸òñÿ óçåë òîëüêî ñ ëåâûì ïîòîìêîì
    root = new TreeNode<int>(60, leftleaf, nullptr);

    return root;
}

// çàêîí÷åííîå äåðåâî
TreeNode<int>* createTree4() {

    // ñîçäà¸òñÿ óêàçàòåëè íà óçëû äåðåâà 
    TreeNode<int>* rightleaf, * leftleaf, * root;


    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5        

    rightleaf = new TreeNode<int>(3);
    leftleaf = new TreeNode<int>(1);


    root = new TreeNode<int>(2, leftleaf, rightleaf);

    leftleaf = new TreeNode<int>(5);
    rightleaf = new TreeNode<int>(7, leftleaf, nullptr);

    root = new TreeNode<int>(4, root, rightleaf);

    leftleaf = new TreeNode<int>(9);
    rightleaf = new TreeNode<int>(30);

    rightleaf = new TreeNode<int>(10, leftleaf, rightleaf);

    root = new TreeNode<int>(8, root, rightleaf);

    return root;
}



TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}