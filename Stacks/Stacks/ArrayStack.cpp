/*
	ArrayStack.cpp -> Implementation of ArrayStack file.
	Author: Tanmay Fadnavis
*/

#include"ArrayStack.h"
#include<iostream>


//----------------------Function to push---------------------
void Stack::push(const int& t) {
	elem.push_back(t);
}

//----------------------Function to pop-------------------------
int Stack::pop() {
	if (empty()) {
		throw std::out_of_range("underflow");
	}
	auto x = elem.back();
	elem.pop_back();
	return x;
} 

//--------------------Function to peek-------------------------
int Stack::peek() {
	if (empty()) {
		throw std::out_of_range("underflow");
	}
	return elem.back();
}

//-------------------Function to display-----------------------
void Stack::display()
{
	std::cout << "The content are \n";
	for (std::vector<int>::iterator it = elem.begin(); it != elem.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}