/*
	Executive.cpp -> This is the driver class for graph algorithms.
	Author: Tanmay Fadnavis
*/

#include"Graphs.h"
#include<iostream>
#include<vector>

int main(int argc, char* argv)
{
	Graphs g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 3);
	g.addEdge(1, 5);
	g.addEdge(3, 6);
	g.addEdge(5, 6);
	g.addEdge(6, 4);
	g.addEdge(4, 2);

	g.DFS();
	std::cout << "\n";
	g.BFS();
	getchar();
}