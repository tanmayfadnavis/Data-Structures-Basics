/*
	Node.cpp -> Implementation class for Node.
	Author: Tanmay Fadnavis
	Desp -> It just has parameterized constructor as of now.
*/

#include "Node.h"

//----------------------Default constructor------------------------
Node::Node()
{

}

//-----------------------Parameterized Constructor-------------------
Node::Node(const int value) :data(value), left(nullptr), right(nullptr)
{

}