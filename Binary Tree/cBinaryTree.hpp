/*
 * cBinarytree.hpp
 *
 *  Created on: Apr 16, 2017
 *      Author: Amit
 */

#ifndef CBINARYTREE_HPP_
#define CBINARYTREE_HPP_

#include <iostream>
#include <queue>

#define DEBUG	0

using namespace std;

template<class type>
struct sBinaryTree
{
	type data;
	sBinaryTree* left;
	sBinaryTree* right;
};

template<class type>
class cBinaryTree
{
protected:
	sBinaryTree<type>* root;
	int count;

public:
	bool addNode(type data);

	bool deleteNode(type data);

	sBinaryTree<type>* searchNode(type data);

	bool printBTree();

	cBinaryTree();

	~cBinaryTree();

private:
	bool deleteFromTree(sBinaryTree<type>* &node);
	void destroyTree(sBinaryTree<type>* base);
};

template<class type>
bool cBinaryTree<type>::addNode(type data)
{
	sBinaryTree<type>* newNode = new sBinaryTree<type>;
	sBinaryTree<type>* current=NULL;

	if(!newNode)
	{
		cout << "Memory Error";
		return false;
	}

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if(root==NULL)
	{
		root = newNode;
		count++;
#if DEBUG
		cout << "addNode:Root created, returning to main\n";
#endif/*#if DEBUG*/
		return true;
	}

	queue <sBinaryTree<type>* > travarseQueue;
	travarseQueue.push(root);
	while(!travarseQueue.empty())
	{
		current = travarseQueue.front();
		travarseQueue.pop();

		if(current->left!= NULL)
			travarseQueue.push(current->left);
		else
		{
			current->left = newNode;
			count++;
#if DEBUG
			cout << "Inserting " << newNode->data << "on left of "<< current->data << endl;
#endif/*#if DEBUG*/
			//queue destructor call
			return true;
		}

		if(current->right)
			travarseQueue.push(current->right);
		else
		{
			current->right = newNode;
			count++;
#if DEBUG
			cout << "Inserting " << newNode->data << "on right of "<< current->data << endl;
#endif/*#if DEBUG*/
			//queue destructor call
			return true;
		}
	}
	return false;
};

template <class type>
bool cBinaryTree<type>::deleteNode(type data)
{

	sBinaryTree<type>* current=NULL;

	if (root->data == data)
		return deleteFromTree(root);

	queue <sBinaryTree<type>* > travarseQueue;
	travarseQueue.push(root);
	while(!travarseQueue.empty())
	{
		current = travarseQueue.front();
		travarseQueue.pop();
#if DEBUG
		cout << "Popped:" << current ->data << " \n";
#endif/*if DEBUG*/
		if(current->left)
		{
			travarseQueue.push(current->left);
#if DEBUG
			cout << "Pushed Left:"<<current->left->data << "\n";
#endif/*if DEBUG*/
			if(current->left->data == data)
				return deleteFromTree(current->left);
		}

		if(current->right)
		{
			travarseQueue.push(current->right);
#if DEBUG
			cout << "Pushed Right:"<<current->right->data << "\n";
#endif/*if DEBUG*/
			if(current->right->data == data)
				return deleteFromTree(current->right);
		}
	}

	cout << "Node with data " << data << " not found\n";
	return false;

};

template<class type>
bool cBinaryTree<type>:: deleteFromTree(sBinaryTree<type>* &node)
{
	sBinaryTree<type>* current 		= NULL;
	sBinaryTree<type>* trailCurrent = NULL;

	if(!node)
	{
		cout << "deleteFromTree: Node is empty\n";
		return false;
	}
	else
	{
		if((node->left ==NULL)&&(node->right==NULL))
		{
			current = node;
			node = NULL;
		}
		else if(node->left == NULL)
		{
			current = node;
			node = current ->right;
		}
		else if(node->right == NULL)
		{
			current = node;
			node = current ->left;
		}
		else
		{
			current = node -> left;
			trailCurrent = NULL;
			while(current->right != NULL)
			{
#if DEBUG
				cout << current -> data << endl;;
#endif
				trailCurrent = current;
				current = current->right;
			}

			node->data = current->data;
#if DEBUG
			cout << "After Loop CD: " << current->data << endl;
			cout << "ND: " << node->data << " RD: " << root->data << endl;
			cout << "TCD: " << trailCurrent->data << endl;
#endif/*#if DEBUG*/

			if(trailCurrent == NULL)
				node->left = current->left;
			else
				trailCurrent->right = current->left;
		}

		count--;
		delete current;
#if DEBUG
		cout << "delete current success\n";
#endif/*#if DEBUG*/
		return true;
	}
}

template <class type>
sBinaryTree<type>* cBinaryTree<type>::searchNode(type data)
{
	sBinaryTree<type>* current=NULL;

	queue <sBinaryTree<type>* > travarseQueue;
	travarseQueue.push(root);

	while(travarseQueue.empty())
	{
		current = travarseQueue.pop();

		if(current ->data == data)
		{
			return current;
		}

		if(current->left)
			travarseQueue.push(current->left);

		if(current->right)
			travarseQueue.push(current->right);
	}

	cout << "searchNode:Node with data " << data << " not found\n";

	return NULL;
};

template<class type>
bool cBinaryTree<type>::printBTree()
{
	sBinaryTree<type>* current=NULL;
	unsigned int nodeCount = count;

	queue <sBinaryTree<type>* > travarseQueue;

	if(root==NULL)
	{
		cout << "Tree is Empty\n";
		return false;
	}

	cout << "Level Order traversal:\n";
	cout << "Number of nodes in tree: " <<count << endl;

	travarseQueue.push(root);
	travarseQueue.push(NULL);

	/* Initial break condition was while(!travarseQueue.empty())
	 * But C++ queue.empty() implementation is on size check
	 * which keeps on increasing with NULL insertion as well */
	while(nodeCount)
	{
#if DEBUG
		//cout << !travarseQueue.empty() << endl;
		cout << "In While Loop\n";
#endif/*#if DEBUG*/
		current = travarseQueue.front();
		travarseQueue.pop();

		if(current!=NULL)
		{
			cout << current -> data << " ";
			nodeCount--;

			if(current->left!=NULL)
				travarseQueue.push(current->left);

			if(current->right!=NULL)
				travarseQueue.push(current->right);
		}
		else
		{
			travarseQueue.push(NULL);
			cout << endl;
		}
	}
	cout << endl;
	return true;
};

template<class type>
cBinaryTree<type>:: cBinaryTree()
{
	root = NULL;
	count = 0;
}

/*//Copy Constructor yet to implement
template<class type>
cBinaryTree<type>:: cBinaryTree(sBinaryTree<type>* &otherRoot;)
{
	root = NULL;
	count = 0;
}*/

template<class type>
cBinaryTree<type>::~cBinaryTree()
{

	destroyTree(root);
	root = NULL;
	count = 0;
}

template<class type>
void cBinaryTree<type>::destroyTree(sBinaryTree<type>* base)
{
	if(base == NULL)
		return;
	else
	{
		destroyTree(base->left);
		destroyTree(base->right);
		delete base;
	}
}

#endif /* CBINARYTREE_HPP_ */
