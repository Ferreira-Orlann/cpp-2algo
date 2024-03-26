#include "linkedlist.h"

SUPINFO2ALGO::LinkedList::LinkedList()
{
	first = nullptr;
	lenght = 0;
}

SUPINFO2ALGO::LinkedList::~LinkedList()
{
	
}

void* SUPINFO2ALGO::LinkedList::operator[](int index)
{
	SUPINFO2ALGO::Node* node = getNode(index);
	if (node == nullptr)
		return nullptr;
	return node->getValue();
}

void SUPINFO2ALGO::LinkedList::append(void* value)
{
	insertNode(getNode(lenght - 1), new SUPINFO2ALGO::Node(nullptr, value), nullptr);
	lenght++;
}

void SUPINFO2ALGO::LinkedList::insertFirst(void* value)
{
	insertNode(nullptr, new SUPINFO2ALGO::Node(nullptr, value), first);
	lenght++;
}

bool SUPINFO2ALGO::LinkedList::insert(int index, void* value)
{
	if (index < 0 || index >= lenght) {
		return false;
	}
	insertNode(getNode(index - 1), new SUPINFO2ALGO::Node(nullptr, value), getNode(index));
	lenght++;
	return true;
}

int SUPINFO2ALGO::LinkedList::getIndex(void* value)
{
	SUPINFO2ALGO::Node* node = first;
	for (int i = 0; i < lenght; i++) {
		if (node->getValue() == value)
			return i;
		first = first->getNext();
	}
	return -1;
}

bool SUPINFO2ALGO::LinkedList::has(void* value)
{
	SUPINFO2ALGO::Node* node = first;
	for (int i = 0; i < lenght; i++) {
		if (node->getValue() == value)
			return true;
		first = first->getNext();
	}
	return false;
}

bool SUPINFO2ALGO::LinkedList::removeByIndex(int index)
{
	SUPINFO2ALGO::Node* workingNode = getNode(index);
	if (workingNode == nullptr) {
		return false;
	}
	removeNode(getNode(index - 1), workingNode, getNode(index + 1));
	lenght--;
	return true;
}

bool SUPINFO2ALGO::LinkedList::remove(void* value)
{
	int index = getIndex(value);
	if (index == -1) {
		return false;
	}
	removeNode(getNode(index - 1), getNode(index), getNode(index + 1));
	lenght--;
	return true;
}

bool SUPINFO2ALGO::LinkedList::isEmpty()
{
	return first == nullptr;
}

void SUPINFO2ALGO::LinkedList::print()
{
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
			std::cout << "Index: " << i << " Value: " << value << std::endl;
		node = node->getNext();
	}
}

inline void SUPINFO2ALGO::LinkedList::update(int index, void* value)
{
	getNode(index)->setValue(value);
}

void SUPINFO2ALGO::LinkedList::intBubbleSort()
{
	for (int i = 0; i < lenght - 1; i++) {
		for (int j = 0; j < lenght - i - 1; j++) {
			int* onep = (int*) operator[](j + 1);
			int one = *onep;
			int* twop = (int*) operator[](j);
			int two = *twop;
			if (one < two) {
				swap(j + 1, j);
			}
		}
	}
}

bool SUPINFO2ALGO::LinkedList::swap(int indexOne, int indexTwo)
{
	if (indexOne < 0 || indexOne >= lenght || indexTwo < 0 || indexTwo >= lenght) {
		return false;
	}
	void* nodeOneValue = getNode(indexOne)->getValue();
	void* nodeTwoValue = getNode(indexTwo)->getValue();
	update(indexOne, nodeTwoValue);
	update(indexTwo, nodeOneValue);
	return true;
}

void SUPINFO2ALGO::LinkedList::removeNode(SUPINFO2ALGO::Node* before, SUPINFO2ALGO::Node* workingNode, SUPINFO2ALGO::Node* after)
{
	if (workingNode == first) {
		first = after;
	}
	if (before != nullptr)
		before->setNext(after);
	if (workingNode != nullptr)
		workingNode->setNext(nullptr);
}

inline void SUPINFO2ALGO::LinkedList::insertNode(SUPINFO2ALGO::Node* before, SUPINFO2ALGO::Node* workingNode, SUPINFO2ALGO::Node* after)
{
	if (before != nullptr) {
		before->setNext(workingNode);
	}
	else
		first = workingNode;
	if (workingNode != nullptr)
		workingNode->setNext(after);
}

SUPINFO2ALGO::Node* SUPINFO2ALGO::LinkedList::getNode(int index)
{
	if (index < 0 || index >= lenght) {
		return nullptr;
	}
	SUPINFO2ALGO::Node* node = this->first;
	for (int i = 1; i <= index; i++) {
		node = node->getNext();
	}
	return node;
}

