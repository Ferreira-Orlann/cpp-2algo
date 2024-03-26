#pragma once

#include "node.h"
#include <iostream>

namespace SUPINFO2ALGO {
	class Queue {
	private:
		SUPINFO2ALGO::Node* first;
		SUPINFO2ALGO::Node* last;
	public:
		void add(void* value);
		void* pop();
		void* poll();
		bool isEmpty();
		void print();
	};
}