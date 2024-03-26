#pragma once

namespace SUPINFO2ALGO {
	class Node {
	private:
		void* value;
		SUPINFO2ALGO::Node* next;
	public:
		SUPINFO2ALGO::Node* getNext() { return next; };
		void* getValue() { return value; };
		void setNext(Node* node) { next = node; };
		void setValue(void* value) { this->value = value; };
		Node(SUPINFO2ALGO::Node* next, void* value);
	};
}