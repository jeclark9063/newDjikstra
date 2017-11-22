#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <string>
#include "Graph.h"
#include "minHeap.h"
#define MAX_NODES 20
using namespace std;

// Driver program to test above functions
int main()
{
	cout << "**********************************************************" << endl;
	cout << "Molly, Abdullah, and Earl's incredible road trip simulator" <<endl;
	cout <<	"Simulates shortest path from Miami to Seattle" << endl;
	cout << "**********************************************************" << endl << endl;
	// create the graph given in above fugure
	int V = 10;
	Graph graph(V);
	graph.addEdge(&graph, 0, 1, 350); 
	graph.addEdge(&graph, 0, 2, 480);
	graph.addEdge(&graph, 1, 2, 160); 
	graph.addEdge(&graph, 1, 4, 350);
	graph.addEdge(&graph, 2, 4, 260);
	graph.addEdge(&graph, 2, 3, 710);
	graph.addEdge(&graph, 3, 5, 742);
	graph.addEdge(&graph, 3, 6, 1170);
	graph.addEdge(&graph, 4, 5, 800);
	graph.addEdge(&graph, 4, 3, 800);
	graph.addEdge(&graph, 5, 6, 1200);
	graph.addEdge(&graph, 5, 8, 600);
	graph.addEdge(&graph, 6, 7, 750);
	graph.addEdge(&graph, 7, 9, 800);
	graph.addEdge(&graph, 8, 9, 1300);
	graph.addEdge(&graph, 8, 7, 1200);
	//graph.addEdge(&graph, 9, 7, 1200);
	graph.dijkstra(&graph, 0);
	system("pause");

	return 0;
}