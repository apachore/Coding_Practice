//============================================================================
// Name        : clinkedList.hpp
// Author      : Amit pachore 
// Version     :
// Description : LinkedList class declaration
//============================================================================

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

template <class Type>
struct node
{
	Type info;
	node * next;
};

template <class Type>
class linkedList
{

private:

	void copyList(const linkedList<Type>&);

	node<Type> * firstNode;
	node<Type> * lastNode;

public:

	int count;

	void addNode(const Type);

	void deleteNode(const Type);

	void reverseList();

	void destroyList();

	void sort();

	node<Type>* searchNode(const Type );

	void printList();

	linkedList();

	linkedList(const linkedList<Type> &);

	~linkedList();

};

//============================================================================
// Name        : clinkedList.cpp
// Author      : Amit pachore 
// Version     :
// Description : LinkedList class implementation
//============================================================================

#include <iostream>
#include "clinkedList.hpp"

using namespace std;

template<class Type>
void linkedList<Type>::copyList(const linkedList<Type>& otherList)
{
	node<Type> *newNode;
	node<Type> *currentNode;

	//cout << "In copy List" << endl;

	//cout <<"In CopyList Fisrt Node:"<< firstNode << endl;

	if(firstNode != NULL)
	{
		//cout << "First Node not NULL" << endl;
		destroyList();
	}
	/*if(this == &otherList)
	{
		cout << "Cannot copy to same list"<<endl;
		return;
	}*/

	if(otherList.firstNode == NULL)
	{
		//cout << "Other List first node not NULL" << endl;
		firstNode = NULL;
		lastNode = NULL;
		count = 0;
		return;
	}
	else
	{
		//cout << "Other list Copying one by one" << endl;

		currentNode = otherList.firstNode;

		count = otherList.count;

		//cout << "Count in CopyList:" << count << endl;

		firstNode = new node<Type>;
		firstNode->info = currentNode->info;
		firstNode->next = NULL;
		lastNode = firstNode;

		currentNode = currentNode->next;

		while(currentNode != NULL)
		{
			newNode = new node<Type>;
			newNode->info = currentNode->info;
			newNode->next = NULL;

			lastNode->next = newNode;
			lastNode = newNode;
			currentNode = currentNode->next;
		}
	}
}

template<class Type>
void linkedList<Type>::addNode(const Type value)
{
	node<Type>* newNode;
	newNode = new node<Type>;
	newNode->info = value;
	newNode->next = NULL;

	if(firstNode == NULL)
	{
		firstNode = newNode;
		lastNode = firstNode;
		count++;
	}
	else
	{
		lastNode ->next = newNode;
		lastNode = newNode;
		count++;
	}
}
template<class Type>
void linkedList<Type>::deleteNode(const Type value)
{
	node<Type>* currentNode=NULL;
	node<Type>* prevNode=NULL;

	bool found = false;

	if(firstNode->info== value)
	{
		currentNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		prevNode = firstNode;
		currentNode = firstNode->next;

		while(currentNode!= NULL && !found)
		{
			if(currentNode->info == value)
			{
				found = true;
				break;
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
		}

		if(currentNode == lastNode)
		{
			lastNode = prevNode;
		}
		else if(currentNode == NULL)
		{
			cout << value << " Value Node not found" << endl;
			return;
		}

		prevNode->next = currentNode->next;
	}

	delete currentNode;
	count--;
}

template<class Type>
node<Type>* linkedList<Type>::searchNode(const Type value)
{
	bool found = false;
	node<Type>* currentNode;
	currentNode = firstNode;

	while(currentNode && !found)
	{
		if(currentNode->info == value)
		{
			found = true;
			break;
		}
		currentNode = currentNode->next;
	}

	if(currentNode == NULL)
	{
		cout << value << " not found in list" << endl;
		return NULL;
	}

	return currentNode;
}

template<class Type>
void linkedList<Type>::reverseList()
{
	node<Type>* currentNode=NULL;
	node<Type>* nextNode=NULL;
	node<Type>* prevNode=NULL;

	if(firstNode == NULL || firstNode->next == NULL)
		cout << "List is empty or has only one node" << endl;

	currentNode = firstNode;
	while(currentNode)
	{
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}

	lastNode = firstNode;
	firstNode = prevNode;
}

template<class Type>
void linkedList<Type>::destroyList()
{
	node<Type>* current;

	//cout << "In destroy List" << endl;

	while(firstNode != NULL)
	{
		current = firstNode;
		firstNode = firstNode->next;
		delete current;
	}

	lastNode = NULL;
	count = 0;
}

template<class Type>
void linkedList<Type>::sort()
{

}

template<class Type>
linkedList<Type>::linkedList()
{
	firstNode = NULL;
	lastNode = NULL;
	count = 0;
}

template<class Type>
linkedList<Type>::linkedList(const linkedList<Type>& otherList)
{

	firstNode = NULL;
	lastNode = NULL;
	count =0;

	//cout << "In copy constructor" << endl;
	//if(this != &otherList)
	//{
		copyList(otherList);
	//}
	
}

template<class Type>
linkedList<Type>::~linkedList()
{
	destroyList();
}

template<class Type>
void linkedList<Type>::printList()
{
	node<Type>* currentNode = firstNode;

	while(currentNode)
	{
		cout << currentNode->info << " ";
		currentNode = currentNode->next;
	}

	cout << endl;
}

#endif /* LINKEDLIST_HPP_ */
