/*
	PriorityQueue.cpp -> Implementation of functions.
	Author: Tanmay Fadnavis
*/

#include"PriorityQueue.h"
#include<vector>
#include<iostream>

PriorityQueue::PriorityQueue()
{

}

//-----------------------Function to extract minimum element(or root) from heap-------------------------
int PriorityQueue::extractMin()
{
	int data;
	if (arr.size() == 1)
	{
		data = arr.back();
		arr.pop_back();
		return data;
	}

	data = arr[0]; // store the min value.
	arr[0] = arr[arr.size() - 1]; // substitute last value to 0.
	arr.pop_back(); // remove the last value.
	minHeapify(0);
}

//-----------------------Function to insert into priority queue-----------------------
void PriorityQueue::insert(int k)
{
	arr.push_back(k);

	int i = arr.size()-1;

	while (i !=0 && arr[parent(i)] > arr[i])
	{
		std::swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

//-----------------------Function to delete item from priority queue------------------
void PriorityQueue::deleteKey(int i)
{
	std::cout << " Implemented Later\n";
}

//------------------------Function to min heapify-------------------------------------
void PriorityQueue::minHeapify(int i)
{
	int l = leftChild(i);
	int r = rightChild(i);
	int smallest = i;

	if (l < arr.size() && arr[l] < arr[i])
		smallest = l;
	if (r < arr.size() && arr[r] < arr[smallest])
		smallest = r;

	if (smallest != i)
	{
		std::swap(arr[i], arr[smallest]);
		minHeapify(smallest);
	}

}
