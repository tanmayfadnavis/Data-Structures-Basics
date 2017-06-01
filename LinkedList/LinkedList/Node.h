#ifndef NODE_H
#define NODE_H

/*
	Node.h : This is the header file for Node Class. It contains default constructor, copy constructor, copy assignment.
	Author: Tanmay Fadnavis
*/

class Node
{
	private:
		int data;
		Node* next;
		Node* prev;
	public:
		Node(); // Default Constructor.
		Node(const int value); // Parameterized Constructor.
		Node(const Node& n); //Copy constructor.
		Node& operator=(const Node& n) =delete; // Copy assignment Operator.
		

		void setData(int value);
		void setNext(Node* nxt);
		void setPrev(Node* prev);
	    int getData();
		Node* getNext();
		Node* getPrev();

};


#endif
