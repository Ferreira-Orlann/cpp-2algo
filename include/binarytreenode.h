#pragma once

namespace SUPINFO2ALGO {
	template<typename T>
	class BinaryTreeNode {
	private: 
		BinaryTreeNode* right;
		BinaryTreeNode* left;
		T value;
	public:
		BinaryTreeNode();
		BinaryTreeNode(BinaryTreeNode* left, T value, BinaryTreeNode* right);
		void setRight(BinaryTreeNode* right);
		void setLeft(BinaryTreeNode* left);
		void setValue(T value);
		BinaryTreeNode* getRight();
		BinaryTreeNode* getLeft();
		T getValue();
	};
}

template<typename T>
inline SUPINFO2ALGO::BinaryTreeNode<T>::BinaryTreeNode()
{
	left = nullptr;
	right = nullptr;
	value = nullptr;
}

template<typename T>
inline SUPINFO2ALGO::BinaryTreeNode<T>::BinaryTreeNode(BinaryTreeNode* left, T value, BinaryTreeNode* right)
{
	this->left = left;
	this->right = right;
	this->value = value;
}

template<typename T>
inline void SUPINFO2ALGO::BinaryTreeNode<T>::setRight(BinaryTreeNode* right)
{
	this->right = right;
}

template<typename T>
inline void SUPINFO2ALGO::BinaryTreeNode<T>::setLeft(BinaryTreeNode* left)
{
	this->left = left;

}

template<typename T>
inline void SUPINFO2ALGO::BinaryTreeNode<T>::setValue(T value)
{
	this->value = value;
}

template<typename T>
inline SUPINFO2ALGO::BinaryTreeNode<T>* SUPINFO2ALGO::BinaryTreeNode<T>::getRight()
{
	return right;
}

template<typename T>
inline SUPINFO2ALGO::BinaryTreeNode<T>* SUPINFO2ALGO::BinaryTreeNode<T>::getLeft()
{
	return left;
}

template<typename T>
inline T SUPINFO2ALGO::BinaryTreeNode<T>::getValue()
{
	return value;
}
