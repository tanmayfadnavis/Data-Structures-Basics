/*
	Executive.cpp -> This is the executive class for Dynamic Programming.
	Author: Tanmay Fadnavis
*/

#include"DynamicProgramming.h"
#include<vector>
#include<string>
#include<iostream>

int main(int argc, char* argv)
{
	DynamicProgramming dp;
	
	//Vectors for 0/1 KnapSack problem.
	std::vector<int> weights = { 1,3,4,5 };
	std::vector<int> values = { 1,4,5,7 };
	int totalWt = 8;

	dp.zeroOneKnapSack(totalWt, weights, values);

	std::string s1 = "abcdaf";
	std::string s2 = "acbcf";

	dp.longestSubSequence(s1, s2);

	getchar();
}