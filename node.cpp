#include "node.h"

SUPINFO2ALGO::Node::Node(SUPINFO2ALGO::Node* next, void* value)
{
	setNext(next);
	setValue(value);
}