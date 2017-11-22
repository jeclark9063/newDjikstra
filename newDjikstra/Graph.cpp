#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <string>
#include "Graph.h"
#include "minHeap.h"
#define MAX_NODES 20
using namespace std;

Graph::Graph(int mV) {
	V = mV;
	// Create an array of adjacency lists.  Size of array will be V
	adjList = (struct AdjList*) malloc(V * sizeof(struct AdjList));
	// Initialize each adjacency list as empty by making head as NULL
	for (int i = 0; i < V; i++)
		adjList[i].head = NULL;
}

void Graph::addEdge(Graph* graph, int src, int dest, int weight)
{
	// Add an edge from src to dest.  A new node is added to the adjacency
	// list of src.  The node is added at the begining
	struct AdjListNode*  newNode = graph->newAdjListNode(dest, weight);
	newNode->next = graph->adjList[src].head;
	graph->adjList[src].head = newNode;
}

// The main function that calulates distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
void Graph::dijkstra(Graph* graph, int src)
{
	int dist[MAX_NODES];      // dist values used to pick minimum weight edge in cut

					  // minHeap represents set E
	MinHeap minHeap(MAX_NODES);

	// Initialize min heap with all vertices. dist value of all vertices 
	for (int v = 0; v < MAX_NODES - 1; ++v)
	{
		dist[v] = INT_MAX;
		minHeap.nodeArray[v] = minHeap.newMinHeapNode(v, dist[v]);
		minHeap.pos[v] = v;
	}

	// Make dist value of src vertex as 0 so that it is extracted first
	minHeap.nodeArray[src] = minHeap.newMinHeapNode(src, dist[src]);
	minHeap.pos[src] = src;
	dist[src] = 0;
	minHeap.decreaseKey(&minHeap, src, dist[src]);

	// Initially size of min heap is equal to V
	minHeap.size = V;

	//array to keep track of path
	int path[MAX_NODES] = { NULL };

	// In the following loop, min heap contains all nodes
	// whose shortest distance is not yet finalized.
	while (!minHeap.isEmpty(&minHeap))
	{
		// Extract the vertex with minimum distance value
		MinHeap::MinHeapNode* minHeapNode = minHeap.extractMin(&minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number

								// Traverse through all adjacent vertices of u (the extracted
								// vertex) and update their distance values
		AdjListNode* pCrawl = graph->adjList[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is not finalized yet, and distance to v
			// through u is less than its previously calculated distance
			if (minHeap.isInMinHeap(&minHeap, v) && dist[u] != INT_MAX &&
				pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;
				//set city that changed it
				path[v] = u;
				switch (u) {
				case 0:
					cout << "Miami to ";
					break;
				case 1:
					cout << "Jacksonville to ";
					break;
				case 2:
					cout << "Tallahassee to ";
					break;
				case 3:
					cout << "Houston to ";
					break;
				case 4:
					cout << "Atlanta to ";
					break;
				case 5:
					cout << "Kansas City to ";
					break;
				case 6:
					cout << "Phoenix to ";
					break;
				case 7:
					cout << "San Francisco to ";
					break;
				case 8:
					cout << "Denver to ";
					break;
				case 9:
					cout << "Seattle to ";
					break;
				}
				switch (v) {
				case 0:
					cout << "Miami is " << dist[v] << endl;
					break;
				case 1:
					cout << "Jacksonville is " << dist[v] << endl;
					break;
				case 2:
					cout << "Tallahassee is " << dist[v] << endl;
					break;
				case 3:
					cout << "Houston is " << dist[v] << endl;
					break;
				case 4:
					cout << "Atlanta is " << dist[v] << endl;
					break;
				case 5:
					cout << "Kansas City is " << dist[v] << endl;
					break;
				case 6:
					cout << "Phoenix is " << dist[v] << endl;
					break;
				case 7:
					cout << "San Francisco is " << dist[v] << endl;
					break;
				case 8:
					cout << "Denver is " << dist[v] << endl;
					break;
				case 9:
					cout << "Seattle is " << dist[v] << endl;
					break;
				}

				// update distance value in min heap also
				minHeap.decreaseKey(&minHeap, v, dist[v]);
			}
			else {
				cout << "Shorter path to ";
				switch (v) {
				case 0:
					cout << "Miami already exists!" << endl;
					break;
				case 1:
					cout << "Jacksonville already exists!" << endl;
					break;
				case 2:
					cout << "Tallahassee already exists!" << endl;
					break;
				case 3:
					cout << "Houston already exists!" << endl;
					break;
				case 4:
					cout << "Atlanta already exists!" << endl;
					break;
				case 5:
					cout << "Kansas City already exists!" << endl;
					break;
				case 6:
					cout << "Phoenix already exists!" << endl;
					break;
				case 7:
					cout << "San Francisco already exists!" << endl;
					break;
				case 8:
					cout << "Denver already exists!" << endl;
					break;
				case 9:
					cout << "Seattle to already exists!" << endl;
					break;
				}
			}
			pCrawl = pCrawl->next;
		}
		cout << endl;
		cout << "**********************************************************" << endl;
		cout << "RETRIEVING NEXT NODE FROM HEAP" << endl;
		cout << "**********************************************************" << endl << endl;
		system("pause");
		system("CLS");
	}
	system("pause");
	system("CLS");
	// print the calculated shortest distances
	minHeap.printArr(dist, V);

	//start at seattle and retrace path to origin, finding shortest path
	system("pause");
	system("CLS");
	cout << "**********************************************************" << endl;
	cout << "Shortest calculated path from Miami to Seattle is" << endl;
	cout << "**********************************************************" << endl << endl;
	int cityNode = 9;
	while (cityNode != 0){
		switch (cityNode) {
		case 0:
			cout << "Miami<----";
			cityNode = path[cityNode];
			break;
		case 1:
			cout << "Jacksonville<----";
			cityNode = path[cityNode];
			break;
		case 2:
			cout << "Tallahassee<----";
			cityNode = path[cityNode];
			break;
		case 3:
			cout << "Houston<----";
			cityNode = path[cityNode];
			break;
		case 4:
			cout << "Atlanta<----";
			cityNode = path[cityNode];
			break;
		case 5:
			cout << "Kansas City<----";
			cityNode = path[cityNode];
			break;
		case 6:
			cout << "Phoenix<----";
			cityNode = path[cityNode];
			break;
		case 7:
			cout << "San Francisco<----";
			cityNode = path[cityNode];
			break;
		case 8:
			cout << "Denver<----";
			cityNode = path[cityNode];
			break;
		case 9:
			cout << "Seattle<----";
			cityNode = path[cityNode];
			break;
		}
	}
	cout << "Miami" << endl << endl;
}

// A utility function to create a new adjacency list node
Graph::AdjListNode* Graph::newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode =
		(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}