#include "2ALGO.h"
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
#include "binarytree.h"

void log_print(std::string str) {
	std::cout << str << std::endl;
}

using namespace SUPINFO2ALGO;

int main()
{
	log_print("============= LinkedList ============= ");

	LinkedList list = LinkedList();
	list.append(new int(90));
	list.insertFirst(new int(100));
	list.append(new int(60));
	list.insert(1, new int(2));
	list.printTyped<int>();
	list.intBubbleSort();
	list.printTyped<int>();

	log_print("============= Stack ============= ");

	Stack stack = Stack();
	stack.push(new int(10));
	stack.push(new int(20));
	stack.push(new int(10));
	stack.push(new int(10));
	stack.push(new int(30));
	stack.pop();
	stack.print();

	log_print("============= Queue ============= ");
	Queue queue = Queue();
	queue.add(new int(10));
	queue.add(new int(10));
	queue.add(new int(10));
	queue.print();
	queue.pop();
	queue.print();

	log_print("============= BinaryTree ============= ");
	BinaryTree<int> binaryTree = BinaryTree<int>();    
	binaryTree.insert(9);
	binaryTree.insert(12);
	binaryTree.insert(6);
	binaryTree.insert(4);
	binaryTree.insert(5);
	binaryTree.insert(3);
	binaryTree.insert(15);
	binaryTree.insert(16);
	binaryTree.insert(13);
	binaryTree.insert(10);
	binaryTree.insert(11);
	binaryTree.remove(5);
	binaryTree.remove(12);
	binaryTree.print();

	return 0;
}
