/*
	Node.cpp -> Implementation of Node Class.
	Author: Tanmay Fadnavis.
*/

#include "Node.h"


Node::Node()
{
}

//-----------Parameterized Constructor------------------
Node::Node(const int value) : next(nullptr), prev(nullptr),data(value)
{

}

//----------Copy Constructor----------------------------
Node::Node(const Node& n) : data(n.data), next(n.next)
{

}

//-------------Set data-----------------------------
void Node::setData(const int value)
{
	data = value;
}

//--------------Set Next-----------------------------
void Node::setNext(Node* nxt)
{
	next = nxt;
}

//--------------Set Prev-------------------------------
void Node::setPrev(Node* prv)
{
	prev = prv;
}

//---------------Get dATA-------------------------------
int Node::getData()
{
	return data;
}

//-----------Get Next Pointer---------------------
Node* Node::getNext()
{
	return next;
}

//------------Get Prev Pointer-------------------
Node* Node::getPrev()
{
	return prev;
}

