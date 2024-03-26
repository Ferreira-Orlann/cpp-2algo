#include "stack.h"

SUPINFO2ALGO::Stack::Stack()
{
	last = nullptr;
}

void SUPINFO2ALGO::Stack::push(void* value)
{
	SUPINFO2ALGO::Node* node = new Node(nullptr, value);
	if (!isEmpty())
		node->setNext(last);
	last = node;
}

void* SUPINFO2ALGO::Stack::pop()
{
	if (isEmpty())
		return nullptr;
	SUPINFO2ALGO::Node* node = last;
	last = node->getNext();
	return node->getValue();
}

void* SUPINFO2ALGO::Stack::top()
{
	if (isEmpty())
		return nullptr;
	return last->getValue();
}

bool SUPINFO2ALGO::Stack::isEmpty()
{
	return last == nullptr;
}

void SUPINFO2ALGO::Stack::print()
{
	SUPINFO2ALGO::Node* node = last;
	while(node != nullptr) {
		void* value = node->getValue();
		if (value == nullptr) {
			std::cout << "Value: nullptr" << std::endl;
		}
		else
			std::cout << "Value: " << value << std::endl;
		node = node->getNext();
	}
}





