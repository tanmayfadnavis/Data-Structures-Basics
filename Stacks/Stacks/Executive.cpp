/*
	Executive.cpp -> This is the driving class for stack.
	Author: Tanmay Fadnavis
*/

#include"ArrayStack.h"
#include<vector>
#include<iostream>

int main(int argc, char *argv[])
{

	Stack s;
	s.push(45);
	s.push(4);
	s.push(3);
	s.push(88);
	s.display();
	int i = s.pop();
	std::cout << i;
	s.display();
	std::cout << s.peek();
	getchar();
}
