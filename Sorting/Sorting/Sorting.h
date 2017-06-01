#ifndef SORTING_H
#define SORTING_H

#include<vector>

class Sorting
{
private:
	void merge(std::vector<int>& list, int left, int mid, int right);
	int partition(std::vector<int>& list, int low, int high);
public:
	void BubbleSort(std::vector<int>& list);
	void SelectionSort(std::vector<int>& list);
	void InsertionSort(std::vector<int>& list);
	void ShellSort(std::vector<int>& list);
	void MergeSort(std::vector<int>& list,int left,int right);
	void QuickSort(std::vector<int>& list, int low, int high);
};

#endif
