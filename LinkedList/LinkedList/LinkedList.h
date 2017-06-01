#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
	LinkedList.h -> Header file for Double LinkedList.
	Author: Tanmay Fadnavis.

*/

#include "Node.h"

class LinkedList
{
	private:
		Node* head;
	public:
		LinkedList(); //Default Constructor.
		LinkedList(const LinkedList& ll); //Copy Constructor.
		LinkedList& operator=(const LinkedList& rhs); // Copy Assignment.
		~LinkedList(); // Destructor.

		void addData(int data);
		void addDataInMid(int position,int data);
		void addDataEnd(int data);
		void printList();
		void delBegNode();
		void delEndNode();
		void delMidNode(int position);
		void nthFromEnd(int n);
		void insertSorted(int value);
		void reverseList();
		void printReverse(Node* head);
		Node* getHead();
		void reverseInPairs();
		void reversePairsK(int k);
		int countNodes();

};

#endif
