#ifndef GRAPHS_H
#define GRAPHS_H

#include<vector>

class Graphs
{

	private:
		int V; // No. of Vertices.
		std::vector<std::vector<int>> adjList;
		void DFSUtil(int v, bool visited[]);
	public:
		Graphs(int V);
		void addEdge(int v, int w);
		void DFS();
		void BFS();
};

#endif
