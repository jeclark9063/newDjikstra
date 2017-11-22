#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <string>
#include "minHeap.h"
using namespace std;

//creates new minheapnode
MinHeap::MinHeapNode* MinHeap::newMinHeapNode(int v, int dist) {
	struct MinHeapNode* minHeapNode =
		(struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

//create a Min Heap
MinHeap::MinHeap(int capacity)
{
	size = 0;
	capacity = capacity;
	nodeArray =
		(struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
	pos = (int *)malloc(capacity * sizeof(int));
}

//swaps heap nodes
void MinHeap::swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void MinHeap::minHeapify(MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size &&
		minHeap->nodeArray[left]->dist < minHeap->nodeArray[smallest]->dist)
		smallest = left;

	if (right < minHeap->size &&
		minHeap->nodeArray[right]->dist < minHeap->nodeArray[smallest]->dist)
		smallest = right;

	if (smallest != idx)
	{
		// The nodes to be swapped in min heap
		MinHeap::MinHeapNode* smallestNode = minHeap->nodeArray[smallest];
		MinHeap::MinHeapNode* idxNode = minHeap->nodeArray[idx];

		// Swap positions
		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		// Swap nodes
		minHeap->swapMinHeapNode(&minHeap->nodeArray[smallest], &minHeap->nodeArray[idx]);

		minHeapify(minHeap, smallest);
	}
}

//function to check if empty
int MinHeap::isEmpty(MinHeap* minHeap)
{
	return minHeap->size == 0;
}

MinHeap::MinHeapNode* MinHeap::extractMin(MinHeap* minHeap)
{
	if (minHeap->isEmpty(minHeap))
		return NULL;

	// Store the root node
	struct MinHeapNode* root = minHeap->nodeArray[0];

	// Replace root node with last node
	struct MinHeapNode* lastNode = minHeap->nodeArray[minHeap->size - 1];
	minHeap->nodeArray[0] = lastNode;

	// Update position of last node
	minHeap->pos[root->v] = minHeap->size - 1;
	minHeap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root
	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}

// Function to decreasy dist value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void MinHeap::decreaseKey(MinHeap* minHeap, int v, int dist)
{
	// Get the index of v in  heap array
	int i = minHeap->pos[v];

	// Get the node and update its dist value
	minHeap->nodeArray[i]->dist = dist;

	// Travel up while the complete tree is not hepified.
	// This is a O(Logn) loop
	while (i && minHeap->nodeArray[i]->dist < minHeap->nodeArray[(i - 1) / 2]->dist)
	{
		// Swap this node with its parent
		minHeap->pos[minHeap->nodeArray[i]->v] = (i - 1) / 2;
		minHeap->pos[minHeap->nodeArray[(i - 1) / 2]->v] = i;
		minHeap->swapMinHeapNode(&minHeap->nodeArray[i], &minHeap->nodeArray[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool MinHeap::isInMinHeap(MinHeap *minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->size)
		return true;
	return false;
}

// A utility function used to print the solution
void MinHeap::printArr(int dist[], int n)
{
	cout << "Shortest path from Miami to every other node in the list" << endl << endl;
	printf("Vertex   Distance from Source\n");
	cout << "**********************************************************" << endl;
	for (int i = 0; i < n; ++i)
		switch (i) {
		case 0:
			cout << "Miami		" << dist[i] << endl;
			break;
		case 1:
			cout << "Jacksonville	" << dist[i] << endl;
			break;
		case 2:
			cout << "Tallahassee	" << dist[i] << endl;
			break;
		case 3:
			cout << "Houston		" << dist[i] << endl;
			break;
		case 4:
			cout << "Atlanta		" << dist[i] << endl;
			break;
		case 5:
			cout << "Kansas City	" << dist[i] << endl;
			break;
		case 6:
			cout << "Phoenix		" << dist[i] << endl;
			break;
		case 7:
			cout << "San Francisco	" << dist[i] << endl;
			break;
		case 8:
			cout << "Denver		" << dist[i] << endl;
			break;
		case 9:
			cout << "Seattle		" << dist[i] << endl;
			break;
		}
	cout << "**********************************************************" << endl;
}
