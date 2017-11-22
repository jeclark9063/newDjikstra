#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <string>
using namespace std;

// A structure to represent a graph. A graph is an array of adjacency lists.
class Graph
{
public:
	// A structure to represent a node in adjacency list
	struct AdjListNode
	{
		int dest;
		int weight;
		struct AdjListNode* next;
	};
	// A structure to represent an adjacency liat
	struct AdjList
	{
		AdjListNode *head;  // pointer to head node of list
	};
	int V;
	struct AdjList* adjList;
	// creates a graph of V vertices
	Graph(int V);
	// Adds an edge to a directed graph
	void addEdge(Graph* graph, int src, int dest, int weight);

	// The main function that calulates distances of shortest paths from src to all
	// vertices. It is a O(ELogV) function
	void dijkstra(Graph* graph, int src);

	// A utility function to create a new adjacency list node
	struct AdjListNode* newAdjListNode(int dest, int weight);
};