#ifndef DYNAMICPROGRAMMING_H
#define DYNAMICPROGRAMMING_H


/*
	Dynamic Programming.h -> This is the header file for dynamic programming random questions. There is no privaate, juts public methods.
	Author: Tanmay Fadnavis
*/

#include<vector>
#include<string>

class DynamicProgramming
{

private:

public:
	void zeroOneKnapSack(int totalwt, const std::vector<int>& weights, const std::vector<int>& values);
	void longestSubSequence(const std::string& input1, const std::string& input2);

};

#endif
