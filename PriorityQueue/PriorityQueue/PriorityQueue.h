#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

/*
	PriorityQueue.h -> Header file for priority queue using vector.
	Author: Tanmay Fadnavis
*/

#include<vector>
#include<iostream>

class PriorityQueue
{

	private:
		std::vector<int> arr;
		int capacity;
		int heap_size;
	public:
		PriorityQueue();
		int parent(int i) { return (i - 1) / 2; }
		int leftChild(int i) { return (2 * i + 1); }
		int rightChild(int i) { return (2 * i + 2); }
		int extractMin();
		int getMin() { return arr[0]; }
		void insert(int k);
		void deleteKey(int i);
		void minHeapify(int i);


};

#endif
