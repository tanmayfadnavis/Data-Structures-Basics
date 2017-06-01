/*
	Executive.cpp -> This is the main class.
	Author: Tanmay Fadnavis
*/


#include "LinkedList.h"
#include "Node.h"
#include "DoubleLL.h"
#include <iostream>

int main(int argc, char** argv)
{
	LinkedList list;
	Node* head = nullptr;
	list.addData(44);
	list.addData(40);
	list.addData(11);
	list.addData(3);
	list.printList();
	//std::cout << "The total no. of nodes are " << list.countNodes();
	//list.addDataInMid(2, 999);
	list.printList();
	list.addDataEnd(1000);
	list.printList();
	//list.nthFromEnd(5);
	list.insertSorted(1111);
	list.printList();
	list.reverseInPairs();
	list.printList();
	//list.reverseList();
	//head = list.getHead();
	//list.printReverse(head);
	//list.printList();
	getchar();

	/*DoubleLinkedList list1;
	list1.addData(3);
	list1.addData(45);
	list1.addData(999);
	list1.addDataEnd(100);
	list1.addDataInMid(3,28);
	list1.printList();
	list1.delBegNode();
	list1.printList();
	list1.delEndNode();
	list1.printList();
	list1.delMidNode(1);
	list1.printList();*/

}