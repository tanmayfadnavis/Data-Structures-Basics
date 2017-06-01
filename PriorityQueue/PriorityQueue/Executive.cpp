/*
	Executive.cpp -> This is the driver program for priority queue.
	Author: Tanmay Fadnavis
*/

#include"PriorityQueue.h"
#include<iostream>

int main(int argc, char* argv)
{
	PriorityQueue pq;
	pq.insert(5);
	pq.insert(55);
	pq.insert(3);
	int small = pq.getMin();
	pq.extractMin();
	std::cout << "The smallest element is" << pq.getMin();
	getchar();
}