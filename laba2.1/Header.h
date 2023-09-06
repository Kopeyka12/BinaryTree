#pragma once
template <class T>
class BinSTree;

template <class T>
class TreeNode {
private:
	TreeNode<T>* left;
	TreeNode<T>* right;

public:
	T data;

	TreeNode(const T& item, TreeNode<T>* lptr = NULL,
		TreeNode<T>* rptr = NULL);
	TreeNode<T>* Left(void) const;
	TreeNode<T>* Right(void) const;
	friend class BinStree<T>;
};
