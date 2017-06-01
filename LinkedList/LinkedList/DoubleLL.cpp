/*
DoubleLL.cpp -> Implementation of Linked List.
Author: Tanmay Fadnavis.
*/

#include "Node.h"
#include<algorithm>
#include<iostream>
#include "DoubleLL.h"

//----------Default Constructor-----------------------
DoubleLinkedList::DoubleLinkedList()
{
	head = nullptr;
}


//----------------Destructor-----------------------------------
DoubleLinkedList::~DoubleLinkedList()
{
	Node *current = head;

	while (current != NULL) {
		std::cout << "Deleting " << current->getData();
		head = head->getNext();
		delete current;
		current = head;
	}
}

//--------------Add Data at the beginning----------------------
void DoubleLinkedList::addData(int value)
{
	Node* newNode = new Node(value);

	if (head == nullptr)
	{
		head = newNode;

	}
	else
	{
		newNode->setNext(head);
		head->setPrev(newNode);
		head = newNode;
	}

}

//-------------Add Data in middle------------------------
void DoubleLinkedList::addDataInMid(int pos, int value)
{
	Node* curr = head;
	Node* newNode = new Node(value);
	int i = 1;
	while (i < pos && curr != nullptr)
	{
		i++;
		curr = curr->getNext();
	}

	newNode->setNext(curr->getNext());
	curr->setNext(newNode);
	newNode->setPrev(curr);
	newNode->getNext()->setPrev(newNode);
}


//------------Function to add data in the end-----------------
void DoubleLinkedList::addDataEnd(int value)
{
	Node* curr = head;
	Node* newNode = new Node(value);
	while (curr->getNext() != nullptr)
	{
		curr = curr->getNext();
	}

	curr->setNext(newNode);
	newNode->setPrev(curr);
}

//-------------Delete Node from Beg------------------------------
void DoubleLinkedList::delBegNode()
{
	Node* temp = head;
	head = head->getNext();
	head->setPrev(nullptr);
	delete temp;
}


//-------------Delete Node from End------------------------------
void DoubleLinkedList::delEndNode()
{
	Node* curr = head;
	Node* prev = nullptr;

	while (curr->getNext() != nullptr)
	{
		prev = curr;
		curr = curr->getNext();
	}

	prev->setNext(nullptr);
	delete curr;
}

//-------------Delete Node from Mid------------------------------
void DoubleLinkedList::delMidNode(int position)
{
	int i = 0;
	Node* curr = head;
	Node* prev = nullptr;

	while (i < position)
	{
		i++;
		prev = curr;
		curr = curr->getNext();
	}

	prev->setNext(curr->getNext());
	curr->getNext()->setPrev(prev);
	delete curr;

}

//---------------Function to print Data---------------------------
void DoubleLinkedList::printList()
{
	Node* temp = head;
	if (head == nullptr)
		std::cout << "List Is Empty\n";
	else
	{
		while (temp != nullptr)
		{
			std::cout << temp->getData() << "\t";
			temp = temp->getNext();
		}
	}
	std::cout << "\n";
}

//--------------Function to count the no. of nodes-------------------
int DoubleLinkedList::countNodes()
{
	int count = 0;
	Node* temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->getNext();
	}
	return count;
}

