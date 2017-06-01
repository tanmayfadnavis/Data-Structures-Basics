/*
	LinkedList.cpp -> Implementation of Linked List.
	Author: Tanmay Fadnavis.
*/

#include "Node.h"
#include<algorithm>
#include<iostream>
#include "LinkedList.h"

//----------Default Constructor-----------------------
LinkedList::LinkedList()
{
	head = nullptr;
}

//------------Function to get head----------------------

Node* LinkedList::getHead()
{
	return head;
}

//------------Copy Constructor--------------------------------
LinkedList::LinkedList(const LinkedList& ll) : head(nullptr)
{
	 Node* curr = ll.head;

	if (!head && curr)
	{
		head = new Node(curr->getData());
		curr = curr->getNext();
	}

	while (curr)
	{
		Node* newNode = new Node(curr->getData());
		curr = curr->getNext();
	}
}


//------------------Copy Assignment---------------------------
LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	LinkedList temp(rhs);
	std::swap(temp.head, head);
	return *this;
}
//----------------Destructor-----------------------------------
LinkedList::~LinkedList()
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
void LinkedList::addData(int value)
{
	Node* newNode = new Node(value);

	if (head == nullptr)
	{
		head = newNode;
		
	}
	else
	{
		newNode->setNext(head);
		head = newNode;
	}

}

//-------------Add Data in middle------------------------
void LinkedList::addDataInMid(int pos, int value)
{
	Node* curr = head;
	Node* newNode = new Node(value);
	int i = 1;
	while (i < pos && curr!=nullptr)
	{
		i++;
		curr = curr->getNext();
	}
	newNode->setNext(curr->getNext());
	curr->setNext(newNode);
}


//------------Function to add data in the end-----------------
void LinkedList::addDataEnd(int value)
{
	Node* curr = head;
	Node* newNode = new Node(value);
	while (curr->getNext() != nullptr)
	{
		curr = curr->getNext();
	}

	curr->setNext(newNode);
}

//-------------Delete Node from Beg------------------------------
void LinkedList::delBegNode()
{
	Node* temp = head;
	head = head->getNext();
	delete temp;
}


//-------------Delete Node from End------------------------------
void LinkedList::delEndNode()
{
	Node* curr = head;
	Node* prev = nullptr;

	while (curr->getNext()!=nullptr)
	{
		prev = curr;
		curr = curr->getNext();
	}

	prev->setNext(nullptr);
	delete curr;
}

//-------------Delete Node from Mid------------------------------
void LinkedList::delMidNode(int position)
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
	delete curr;

}

//---------------Function to print Data---------------------------
void LinkedList::printList()
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
int LinkedList::countNodes()
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


//--------------Function to get nth node from end---------------------------
void LinkedList::nthFromEnd(int n)
{
	Node* nthNode, *temp;
	nthNode = head;

	int count = 0;

	for (temp = head; temp != nullptr;)
	{
		count++;
		if (count - n > 0)
		{
			nthNode = nthNode->getNext();
		}
		temp = temp->getNext();
	}

	if (count >= n)
	{
		std::cout << "The node value is" << nthNode->getData();
	}
}

//---------------Function to insert value into sorted Linked List---------------------
void LinkedList::insertSorted(int value)
{
	Node* curr = head;
	Node* temp=nullptr;

	Node* newNode = new Node(value);

	if (curr == nullptr)
	{
		head = newNode;
		return;
	}

	while (curr!=nullptr && curr->getData() < value)
	{
		temp = curr;
		curr = curr->getNext();
	}

	newNode->setNext(curr);
	if (temp == nullptr)
	{
		head = newNode;
	}
	else
	{
		temp->setNext(newNode);
	}
}

//-------------------Function to reverse a list-------------------
void LinkedList::reverseList()
{
	Node* newNode = nullptr;
	Node* temp = nullptr;

	while (head != nullptr)
	{
		newNode = head->getNext();
		head->setNext(temp);
		temp = head;
		head = newNode;
	}
	head = temp;
}

//----------------Function to print list in reverse.-----------------
void LinkedList::printReverse(Node* ptr)
{
	if (!ptr)
		return;
	printReverse(ptr->getNext());
	std::cout << ptr->getData();
}

//------------------Function to reverse in pairs-----------------------
void LinkedList::reverseInPairs()
{
	Node* backup = head->getNext();
	Node* temp = head->getNext();
	Node* prev = head;

	while (head!=nullptr && head->getNext()!=nullptr)
	{
		prev->setNext(head->getNext());
		head->setNext(temp->getNext());
		temp->setNext(head);

		if (head->getNext()!=nullptr)
		{
			prev = head;
			head = head->getNext();
			temp = head->getNext();
		}
	}

	head = backup;

}

//--------------------Function to reverse in K pairs----------------------
void LinkedList::reversePairsK(int k)
{

}