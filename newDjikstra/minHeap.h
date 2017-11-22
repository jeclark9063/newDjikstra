#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <string>
using namespace std;

// class to represent a min heap
class MinHeap
{
public:
	// Structure to represent a min heap node
	struct MinHeapNode
	{
		int v;
		int dist;
	};
	int size;      // Number of heap nodes present currently
	int capacity;  // Capacity of min heap
	int *pos;     // This is needed for decreaseKey()
	MinHeapNode** nodeArray;

	//create a new Min Heap Node
	MinHeapNode* newMinHeapNode(int v, int dist);

	//create a Min Heap
	MinHeap(int capacity);

	//swap two nodes of min heap. Needed for min heapify
	void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);

	// heapify at given idx
	// also updates position of nodes when they are swapped.
	// Position is needed for decreaseKey()
	void minHeapify(MinHeap* minHeap, int idx);

	//check if the given minHeap is empty or not
	int isEmpty(MinHeap* minHeap);

	//extract minimum node from heap
	MinHeapNode* extractMin(MinHeap* minHeap);

	// decrease dist value of a given vertex v
	// uses pos[] of min heap to get the current index of node in min heap
	void decreaseKey(MinHeap* minHeap, int V, int dist);

	//check if a given vertex
	// 'v' is in min heap or not
	bool isInMinHeap(MinHeap *minHeap, int V);

	// used to print the solution
	void printArr(int dist[], int n);
};