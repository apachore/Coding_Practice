//============================================================================
// Name        : runBinaryTree.cpp
// Author      : Amit Pachore
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "cBinaryTree.hpp"
using namespace std;

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	cBinaryTree<int> testTree;
	testTree.addNode(10);
	testTree.addNode(20);
	testTree.addNode(15);
	testTree.addNode(54);
	testTree.addNode(57);
	testTree.addNode(40);
	testTree.addNode(34);
	testTree.addNode(100);
	testTree.addNode(68);
	testTree.addNode(33);
	testTree.addNode(49);
	testTree.printBTree();

	//Delete node not existing in tree
	testTree.deleteNode(50);

	//root delete test
	testTree.deleteNode(10);
	testTree.printBTree();

	//leaf node delete test
	testTree.deleteNode(40);
	testTree.printBTree();

	//Node right link empty delete test
	testTree.deleteNode(15);
	testTree.printBTree();

	//Node Both links non-empty delete test
	testTree.deleteNode(54);
	testTree.printBTree();

	//Node left link empty delete test
	testTree.deleteNode(100);
	testTree.printBTree();


	return 0;
}
