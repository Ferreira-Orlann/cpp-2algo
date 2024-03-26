#pragma once

#include "node.h"
#include <iostream>

namespace SUPINFO2ALGO {
	class Stack {
	private:
		SUPINFO2ALGO::Node* last;
	public:
		Stack();
		void push(void* value);
		void* pop();
		void* top();
		bool isEmpty();
		void print();
	};
}