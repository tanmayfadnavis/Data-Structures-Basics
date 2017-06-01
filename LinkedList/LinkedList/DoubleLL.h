#ifndef DOUBLELL_H
#define DOUBLELL_H

/*
DoubleLL.h -> Header file for LinkedList.
Author: Tanmay Fadnavis.

*/

#include "Node.h"

class DoubleLinkedList
{
private:
	Node* head;
public:
	DoubleLinkedList(); //Default Constructor.
	~DoubleLinkedList(); // Destructor.

	void addData(int data);
	void addDataInMid(int position, int data);
	void addDataEnd(int data);
	void printList();
	void delBegNode();
	void delEndNode();
	void delMidNode(int position);
	int countNodes();

};

#endif
