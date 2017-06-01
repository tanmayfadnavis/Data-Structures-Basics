/*
	Executive.cpp -> Driver program for calling sorting algorithms.
	Author: Tanmay Fadnavis
*/

#include"Sorting.h"
#include<vector>
#include<iostream>

int main(int argc, char* argv)
{
	Sorting s;
	std::vector<int> items;
	items.push_back(11);
	items.push_back(45);
	items.push_back(3);
	items.push_back(100);
	items.push_back(50);
	items.push_back(10);

	//Display the original vector.
	for (std::vector<int>::iterator it = items.begin(); it != items.end(); ++it)
		std::cout << *it << "\t";
	std::cout << "\n";

	//s.BubbleSort(items);
	//s.SelectionSort(items);
	//s.InsertionSort(items);
	//s.ShellSort(items);
	//s.MergeSort(items, 0, items.size()-1);
	s.QuickSort(items, 0, items.size() - 1);

	//Display the sorted vector.
	for (std::vector<int>::iterator it = items.begin(); it != items.end(); ++it)
		std::cout << *it << "\t";
	std::cout << "\n";

	getchar();
}