#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

/*
	ArrayStack.h -> Header file for array implementation of stack.
	Author: Tanmay Fadnavis
*/

#include<vector>

class Stack
{
	private:
		std::vector<int> elem;
	public:
		int size() const { return elem.size(); }
		bool empty() const { return elem.empty(); }
		void push(const int&);
		void display();
		int pop();
		int peek();


};


#endif
