#include "queue.h"

void SUPINFO2ALGO::Queue::add(void* value)
{
	if (isEmpty()) {
		first = new SUPINFO2ALGO::Node(nullptr, value);
		last = first;
		return;
	}
	auto newNode = new SUPINFO2ALGO::Node(nullptr, value);
	first->setNext(newNode);
	first = newNode;
}

void* SUPINFO2ALGO::Queue::pop()
{
	if (last != nullptr) {
		auto old = last;
		last = old->getNext();
		return old->getValue();
	}
	return nullptr;
}

void* SUPINFO2ALGO::Queue::poll()
{
	if (last != nullptr)
		return last->getValue();
	return nullptr;
}

bool SUPINFO2ALGO::Queue::isEmpty()
{
	return first == nullptr && last == nullptr;
}

void SUPINFO2ALGO::Queue::print()
{
	SUPINFO2ALGO::Node* node = last;
	while (node != nullptr) {
		void* value = node->getValue();
		if (value == nullptr) {
			std::cout << "Value: nullptr" << std::endl;
		}
		else
			std::cout << "Value: " << value << std::endl;
		node = node->getNext();
	}
}
