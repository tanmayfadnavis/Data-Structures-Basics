/*
	Sorting.cpp -> Implementation of various sorting algorithms.
	Author: Tanmay Fadnavis
*/

#include"Sorting.h"
#include<vector>

//-----------------Bubble Sort:Puts the largest element at the end and bubbles smaller elements to the top--------------------------------
void Sorting::BubbleSort(std::vector<int>& list)
{
	for (int pass = list.size(); pass > 0; pass--)
	{
		for (int i = 0; i < pass - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
				int temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
		}
	}
}

//-------------------Selection Sort:Selects the minimum element from the array and replaces the 1st element and so on-------------------------------
void Sorting::SelectionSort(std::vector<int>& list)
{
	int i,j,min, temp;
	for (i = 0; i < list.size()-1; i++)
	{
		min = i;
		for (int j = i+1; j < list.size(); j++)
		{
			if (list[j] < list[min])
				min = j;
		}

		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

//-----------------Insertion Sort: Inserts element at the right place in array. The elements upto k is sorted after k iterations-----------------------
void Sorting::InsertionSort(std::vector<int>& list)
{
	int v, j, i;

	for (i = 2; i < list.size() ; i++)
	{
		v = list[i];
		j = i;

		while (j >=1 && list[j - 1] > v)
		{
			list[j] = list[j - 1];
			j--;
		}

		list[j] = v;

	}
}

//----------------Shell Sort:Similar to insertion sort, but it avoids comparing adjacent element------------------------------------------
void Sorting::ShellSort(std::vector<int>& list)
{
	int size = list.size();
	// Start with a big gap, then reduce the gap
	for (int gap =  size/ 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (int i = gap; i < size; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = list[i];

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && list[j - gap] > temp; j -= gap)
				list[j] = list[j - gap];

			//  put temp (the original a[i]) in its correct location
			list[j] = temp;
		}
	}

}

//-------------------Merge Sort: Divide and conquer sorting algorithm---------------------------------------
void Sorting::MergeSort(std::vector<int>& list,int left,int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		MergeSort(list, left, mid);
		MergeSort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

//-------------------------Merge: Helper function for merge sort-----------------------------------------------
void Sorting::merge(std::vector<int>& list, int left, int mid, int right)
{
	int i, j, k;
	int end1 = mid - left + 1;
	int end2 = right - mid;
	std::vector<int> leftSide(end1);
	std::vector<int> rightSide(end2);

	for (i = 0; i < end1; i++)
		leftSide[i] = list[left+i];
	for (j = 0; j < end2; j++)
		rightSide[j] = list[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < end1 && j < end2)
	{
		if (leftSide[i] <= rightSide[j])
		{
			list[k] = leftSide[i];
			i++;
		}
		else
		{
			list[k] = rightSide[j];
			j++;
		}
		k++;
	}

	while (i < end1)
	{
		list[k] = leftSide[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < end2)
	{
		list[k] = rightSide[j];
		j++;
		k++;
	}

}

//-----------------------------QuickSort Function----------------------------------------
void Sorting::QuickSort(std::vector<int>& arr, int low, int high)
{
	int pivot;
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		pivot = partition(arr, low, high);

		QuickSort(arr, low, pivot - 1);  // Before pi
		QuickSort(arr, pivot + 1, high); // After pi
	}
}

//------------------------Partition: Helpfer function for Quick Sort----------------------------
int Sorting::partition(std::vector<int>& arr, int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return (i + 1);
}