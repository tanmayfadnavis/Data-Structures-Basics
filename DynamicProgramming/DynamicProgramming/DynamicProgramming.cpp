/*
	Dynamic Programming.cpp -> Implementation file for Dynamic Programming
	Author: Tanmay Fadnavis
*/

#include <iostream>
#include<algorithm>
#include "DynamicProgramming.h"

//-----------------------------------Zero / One KnapSack Function----------------------------------------------
void DynamicProgramming::zeroOneKnapSack(int totalWt, const std::vector<int>& weights, const std::vector<int>& values)
{
	//Array to do the calculation and store the result.
	std::vector<std::vector<int>> T;

	int height = weights.size();
	int width = totalWt + 1;

	T.resize(height); // Setting the height of the array which is the no. of items.
	for (int i = 0; i < height; i++)
		T[i].resize(width); // Columns are the total weights ( 0 - weight ).

	// Fill in the values for the result matrix.

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ( j == 0)
			{
				T[i][j] = 0;
			}
			else if (i == 0 && j >= weights[i])
			{
				T[i][j] = values[i];
			}
			else if (j < weights[i])
			{
				T[i][j] = T[i - 1][j];
			}
			else
			{
				T[i][j] = std::max(values[i]+T[i-1][j-weights[i]],T[i-1][j]);
			}
		}
	}
	std::cout << " Max Value is" << T[weights.size()-1][totalWt];
	//Check the values.
	int row = weights.size() - 1;
	int col = totalWt;

	while (row != 0 || col != 0)
	{
		if (T[row][col] != T[row - 1][col])
		{
			std::cout << "This item is selected whose value is" << values[row] << "\t";
			col = col - weights[row];
		}
		row--;
	}

}

//-------------------------Longest Sub Sequence----------------------------------
void DynamicProgramming::longestSubSequence(const std::string& input1, const std::string& input2)
{
	std::vector<std::vector<int>> T;
	int width = input1.size() + 1;
	int height = input2.size() + 1;

	T.resize(height); // Setting the height of the array which is the no. of items.
	for (int i = 0; i < height; i++)
		T[i].resize(width); // Columns are the total weights ( 0 - weight ).

	//Fill the the table;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || j == 0)
			{
				T[i][j] = 0;
			}
			else if (input2[i-1] == input1[j-1])
			{
				T[i][j] = T[i - 1][j - 1] + 1;
			}
			else
			{
				T[i][j] = std::max(T[i - 1][j], T[i][j - 1]);
			}
		}
	}

	std::cout << "The length of longest sub sequence is:" << T[height-1][width-1];
}
