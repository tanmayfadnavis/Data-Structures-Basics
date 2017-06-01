/*
	Graphs.cpp -> This is the implementation file for Graphs.cpp
	Author: Tanmay Fadnavis
*/

#include"Graphs.h"
#include<vector>
#include<iostream>
#include<queue>

//--------------------------Parameterised constructor for graphs-----------------------------
Graphs::Graphs(int vertices):V(vertices),adjList()
{
	adjList.resize(V);
}

//----------------------------Function to add edge to the graphs------------------------------
void Graphs::addEdge(int v, int w)
{
	adjList[v].push_back(w);
	adjList[w].push_back(v);
}


//-----------------------------Utility function for DFS---------------------------------------
void Graphs::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	std::cout << v << "\t";

	for (auto i = adjList[v].begin(); i != adjList[v].end(); i++)
	{
		if (!visited[*i])
		{
			DFSUtil(*i, visited);
		}
	}
}


//------------------------------Depth First Search---------------------------------------
void Graphs::DFS()
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to print DFS traversal
	// starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			DFSUtil(i, visited);
}

//--------------------------------Breadth First Search--------------------------------------
void Graphs::BFS()
{

	std::queue <int> myQueue;
	bool * visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	if (visited[0] == false) {

		myQueue.push(0);
		visited[0] = true;
		while (!myQueue.empty()) {
			std::vector<int>::iterator i;
			int node = myQueue.front();
			for (i = adjList[node].begin(); i != adjList[node].end(); i++) {
				if (!visited[*i]) {
					std::cout << *i << "\t";
					visited[*i] = true;
					myQueue.push(*i);
				}

			}
			myQueue.pop();
		}
	}
}