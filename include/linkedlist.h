#pragma once

#include "node.h"
#include <iostream>

namespace SUPINFO2ALGO {
	class LinkedList {
	private:
		SUPINFO2ALGO::Node* first;
		int lenght;
	private:
		void removeNode(SUPINFO2ALGO::Node* before, SUPINFO2ALGO::Node* workingNode, SUPINFO2ALGO::Node* after);
		void insertNode(SUPINFO2ALGO::Node* before, SUPINFO2ALGO::Node* workingNode, SUPINFO2ALGO::Node* after);
		SUPINFO2ALGO::Node* getNode(int index);
	public:
		LinkedList();
		~LinkedList();
		void* operator[](int index);
		void append(void* value);
		void insertFirst(void* value);
		bool insert(int index, void* value);
		int getIndex(void* value);
		bool has(void* value);
		bool removeByIndex(int index);
		bool remove(void* value	);
		bool isEmpty();
		void print();
		void update(int index, void* value);
		void intBubbleSort();
		template<typename T>
		void printTyped();
		bool swap(int indexOne, int indexTwo);
	};

	template<typename T>
	inline void LinkedList::printTyped()
	{
		std::cout << "Print Typed" << std::endl;
		std::cout << "Lenght: " << lenght << std::endl;
		SUPINFO2ALGO::Node* node = first;
		for (int i = 0; i < lenght; i++) {
			if (node == nullptr) {
				std::cout << "\Node: nullptr" << std::endl;
			}
			void* value = node->getValue();
			if (value == nullptr) {
				std::cout << "Index: " << i << " Value: nullptr" << std::endl;
			}
			else
				std::cout << "Index: " << i << " Value: " << *(T*)value << std::endl;
			node = node->getNext();
		}
	}
}