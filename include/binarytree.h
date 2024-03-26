#pragma once

#include "binarytreenode.h"

#include <array>
#include <iostream>

namespace SUPINFO2ALGO {
	template<typename T>
	class BinaryTree {
	private:
		BinaryTreeNode<T>* root;
	public:
		std::array<BinaryTreeNode<T>*, 2> getNodeAndParent(T value, BinaryTreeNode<T>* node, BinaryTreeNode<T>* parent);
		BinaryTreeNode<T>* getNode(T value, BinaryTreeNode<T>* node);
		BinaryTreeNode<T>* getNode(T value);
		BinaryTreeNode<T>* getMinimal(BinaryTreeNode<T>* node);
		BinaryTreeNode<T>* getMaximal(BinaryTreeNode<T>* node);
		BinaryTreeNode<T>* getSuccessor(BinaryTreeNode<T>* node);
		BinaryTreeNode<T>* getPredecessor(BinaryTreeNode<T>* node);
		BinaryTree();
		BinaryTree(T value);
		BinaryTree(BinaryTreeNode<T>* root);
		bool insert(T value);
		void print(int profondeur = 3, BinaryTreeNode<T>* node = nullptr);
		bool has(T value);
		T getMinimal();
		T getMaximal();
		bool remove(T value);
	};
}

template<typename T>
std::array<SUPINFO2ALGO::BinaryTreeNode<T>*, 2> SUPINFO2ALGO::BinaryTree<T>::getNodeAndParent(T value, BinaryTreeNode<T>* node, BinaryTreeNode<T>* parent)
{
	if (value == node->getValue())
		return std::array<BinaryTreeNode<T>*, 2>{node, parent};
	else if (value > node->getValue() && node->getRight() != nullptr)
		return getNodeAndParent(value, node->getRight(), node);
	else if (value < node->getValue() && node->getLeft() != nullptr)
		return getNodeAndParent(value, node->getLeft(), node);
	else
		return std::array<BinaryTreeNode<T>*, 2>{nullptr, nullptr};
}

template<typename T>
SUPINFO2ALGO::BinaryTreeNode<T>* SUPINFO2ALGO::BinaryTree<T>::getNode(T value, BinaryTreeNode<T>* node)
{
	if (value == node->getValue())
		return node;
	else if (value > node->getValue() && node->getRight() != nullptr)
		return getNode(value, node->getRight());
	else if (value < node->getValue() && node->getLeft() != nullptr)
		return getNode(value, node->getLeft());
	else
		return nullptr;
}

template<typename T>
SUPINFO2ALGO::BinaryTreeNode<T>* SUPINFO2ALGO::BinaryTree<T>::getNode(T value)
{
	return getNode(value, root);
}

template<typename T>
SUPINFO2ALGO::BinaryTreeNode<T>* SUPINFO2ALGO::BinaryTree<T>::getMinimal(BinaryTreeNode<T>* node)
{
	if (node->getLeft() != nullptr)
		return getMinimal(node->getLeft());
	return node;
}

template<typename T>
SUPINFO2ALGO::BinaryTreeNode<T>* SUPINFO2ALGO::BinaryTree<T>::getMaximal(BinaryTreeNode<T>* node)
{
	if (node->getRight() != nullptr)
		return getMaximal(node->getLeft());
	return node;
}

template<typename T>
SUPINFO2ALGO::BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template<typename T>
inline SUPINFO2ALGO::BinaryTree<T>::BinaryTree(T value)
{
	root = new BinaryTreeNode<T>(nullptr, value, nullptr);
}

template<typename T>
inline SUPINFO2ALGO::BinaryTree<T>::BinaryTree(BinaryTreeNode<T>* root)
{
	this->root = root;
}

template<typename T>
inline bool SUPINFO2ALGO::BinaryTree<T>::insert(T value)
{
	if (root == nullptr) {
		root = new BinaryTreeNode<T>(nullptr, value, nullptr);
		return true;
	}
	std::cout << "Test1" << std::endl;
	BinaryTreeNode<T>* workingNode = root;
	while (workingNode != nullptr)
	{
		std::cout << "Test2" << workingNode << std::endl;
		// Right
		if (workingNode->getValue() < value) {
			std::cout << "Test3" << std::endl;
			if (workingNode->getRight() == nullptr) {
				workingNode->setRight(new BinaryTreeNode<T>(nullptr, value, nullptr));
				return true;
			}
			std::cout << "Test4" << std::endl;
			workingNode = workingNode->getRight();
		}
		// Left
		else if (workingNode->getValue() > value) {
			if (workingNode->getLeft() == nullptr) {
				workingNode->setLeft(new BinaryTreeNode<T>(nullptr, value, nullptr));
				return true;
			}
			workingNode = workingNode->getLeft();
		}
		else {
			workingNode = nullptr;
		}
		std::cout << "Test5" << std::endl;
	}
	return false;
}

template<typename T>
void SUPINFO2ALGO::BinaryTree<T>::print(int profondeur, BinaryTreeNode<T>* node)
{
	if (profondeur == 3 && node == nullptr)
		node = root;
	if (node != nullptr) {
		for (int i = 0; i < profondeur; i++) {
			std::cout << " ";
		}
		std::cout << node->getValue() << std::endl;
		if (node->getLeft() != nullptr) {
			print(profondeur + 3, node->getLeft());
		}
		else {
			for (int i = 0; i < profondeur + 3; i++) {
				std::cout << " ";
			}
			std::cout << ".." << std::endl;
		}
		if (node->getRight() != nullptr) {
			print(profondeur + 3, node->getRight());
		}
		else {
			for (int i = 0; i < 3 + profondeur; i++) {
				std::cout << " ";
			}
			std::cout << ".." << std::endl;
		}
	}
}

template<typename T>
inline bool SUPINFO2ALGO::BinaryTree<T>::has(T value)
{
	return getNode(value) != nullptr;
}

template<typename T>
T SUPINFO2ALGO::BinaryTree<T>::getMinimal()
{
	return getMinimal(root)->getValue();
}

template<typename T>
inline T SUPINFO2ALGO::BinaryTree<T>::getMaximal()
{
	return getMaximal(root)->getValue();
}

template<typename T>
bool SUPINFO2ALGO::BinaryTree<T>::remove(T value)
{
	std::array<BinaryTreeNode<T>*, 2> nodeAndParent = getNodeAndParent(value, root, nullptr);
	bool isLeftChild = nodeAndParent[1]->getLeft() == nodeAndParent[0];
	// No node
	if (nodeAndParent[0] == nullptr)
		return false;
	// Leaf
	if (nodeAndParent[0]->getRight() == nullptr && nodeAndParent[0]->getLeft() == nullptr) {
		if (nodeAndParent[1]->getValue() > value)
			nodeAndParent[1]->setLeft(nullptr);
		else
			nodeAndParent[1]->setRight(nullptr);
	}
	// One Child - Left
	else if (nodeAndParent[0]->getLeft() != nullptr && nodeAndParent[0]->getRight() == nullptr) {
		if (isLeftChild)
			nodeAndParent[1]->setLeft(nodeAndParent[0]->getLeft());
		else
			nodeAndParent[1]->setRight(nodeAndParent[0]->getLeft());
		return true;
	}
	// One Child - Right
	else if (nodeAndParent[0]->getLeft() == nullptr && nodeAndParent[0]->getRight() != nullptr) {
		if (isLeftChild)
			nodeAndParent[1]->setLeft(nodeAndParent[0]->getRight());
		else
			nodeAndParent[1]->setRight(nodeAndParent[0]->getRight());
		return true;
	}
	// Two Childs
	else {
		BinaryTreeNode<T>* successor = getSuccessor(nodeAndParent[0]);
		std::array<BinaryTreeNode<T>*, 2> sucessorAndParent = getNodeAndParent(successor->getValue(), root, nullptr);
		if (sucessorAndParent[1]->getLeft() == sucessorAndParent[0])
			sucessorAndParent[1]->setLeft(sucessorAndParent[0]->getRight());
		else
			sucessorAndParent[1]->setRight(sucessorAndParent[0]->getRight());
		nodeAndParent[0]->setValue(sucessorAndParent[0]->getValue());
		return true;
	}
	return false;
}


template<typename T>
SUPINFO2ALGO::BinaryTreeNode<T>* SUPINFO2ALGO::BinaryTree<T>::getSuccessor(BinaryTreeNode<T>* node)
{
	if (getMaximal() == node->getValue()) {
		return nullptr;
	}
	if (node->getRight() != nullptr) {
		return getMinimal(node->getRight());
	}
	auto nodeAndParent = getNodeAndParent(node->getValue(), root, nullptr);
	BinaryTreeNode<T>* workingAncestor = nodeAndParent[1];
	while (workingAncestor != nullptr) {
		BinaryTree<T> binaryTree = BinaryTree<T>(workingAncestor);
		if (binaryTree.has(node->getValue()))
			return workingAncestor;
		workingAncestor = getNodeAndParent(workingAncestor->getValue(), root, nullptr)[1];
	}
	return nullptr;
}

template<typename T>
SUPINFO2ALGO::BinaryTreeNode<T>* SUPINFO2ALGO::BinaryTree<T>::getPredecessor(BinaryTreeNode<T>* node)
{
	if (getMinimal() == node->getValue()) {
		return nullptr;
	}

}