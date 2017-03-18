//============================================================================
// Name        : main.cpp
// Author      : Amit pachore 
// Version     :
// Description : LinkedList class testing main program
//============================================================================

#include <iostream>
#include "clinkedList.hpp"

using namespace std;

int main() {

	linkedList<int> intList;

	intList.addNode(45);
	intList.addNode(10);
	intList.addNode(84);
	intList.addNode(56);
	intList.addNode(9);
	intList.addNode(2);
	intList.addNode(467);

	intList.printList();

	cout << "Count:" << intList.count << endl;

	linkedList<int> intList2(intList);

	intList.deleteNode(45);

	cout << "Count:" << intList.count << endl;

	intList.printList();

	intList.deleteNode(467);

	cout << "Count:" << intList.count << endl;

	intList.printList();

	intList.deleteNode(56);

	cout << "Count:" << intList.count << endl;

	intList.printList();

	intList.deleteNode(99);

	cout << "Count:" << intList.count << endl;

	//Operations on 2nd list

	intList2.printList();

	node<int>* newNode = intList2.searchNode(84);

	cout << newNode->info<<endl;;

	node<int>* newNode2 = intList2.searchNode(99);

	intList2.reverseList();

	intList2.printList();
}
