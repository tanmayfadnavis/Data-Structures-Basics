#ifndef NODE_H
#define NODE_H

/*
	Node.h -> This is a node class for tress.
	Author: Tanmay Fadnavis.
	Descp: I am keeping the data members as public so that, the binary tree class can directly used them.
	       Copy constructor and assignment operator???
*/

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(); // Default Constructor.
	Node(const int value); // Parameterized Constructor.

};

#endif
