/*
 * BinHeap.cpp
 *
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include "BinHeap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

BinHeap::BinHeap(string arr[], int len) {
	heaplen = 0;
    arrlen = len;
    heap = new string[arrlen];

    for (int i = 0; i < len; i++) {
    	insertHeap(arr[i]);
    }

    printHeap();
}

BinHeap::~BinHeap() {
	delete [] heap;
	}

void BinHeap::printHeap() {
	cout << endl;
	for (int i = 0; i < arrlen;i++) {
		cout << i << ", ";
	}
    cout << endl;

    for (int i = 0; i < heaplen;i++) {
    	cout << heap[i] << ", ";
    }
    cout << endl;
}

int BinHeap::findMax(int x, int y) {
	if ((x < heaplen) && (y < heaplen)) {
		if (heap[x] > heap[y]) {
			return(x);
        }
		else {
			return(y);
		}
	}
    else if (x < heaplen) {
    	return x;
    }

    else return -1;
}

/* ******** Part 1 ******** */
void BinHeap::insertHeap(string s) {
	/* here – look at the .hpp for a description of the method that goes here */
	heap[heaplen] = s;
    bubbleUp(heaplen);
    heaplen++;
}

/* you’re writing this one – this one deletes and then calls bubble down, updating the fields */
string BinHeap::deleteHeap() { // returns the string that was deleted
	/* here – look at the .hpp for a description of the method that goes here */
	string val = heap[0];

	heap[0] = heap[heaplen - 1];
	heaplen--;

	bubbleDown(0);

	return val;
}

/* this method you’re writing – it takes an index (the last index in the HEAP (not the array) and compares the value in
 the index with the value of its parent. If it is greater than the value of the parent, they swap and the current index
 becomes that of its parent. It continues until the two don’t swap or until you hit the root */
void BinHeap::bubbleUp(int i) {
    //Get the index of the parent
    int parentIdx = (i-1)/2;

    //If childValue > parentValue ---> swap the two, current index set to parent index
    //Get the value in the heap of the parent and child
    string parentValue = heap[parentIdx];
    string childValue = heap[i];
    if(childValue > parentValue){
        heap[i] = parentValue;
        heap[parentIdx] = childValue;

        //Only Continue to bubble up until you reach the root
        if(parentIdx != 0){
            bubbleUp(parentIdx);
       }
    }
}

/* this method you’re writing. It takes an index (usually 0) and compares the value at that index with the
 values of the two children (it calls findMax for that). If the value at the index is less than the value of the greatest
 child, it swaps with the greatest child and the index becomes that of the greatest of the two children. It continues
 until either it can’t bubble down any further or until neither child is greater than the parent (the value at the index) */

void BinHeap::bubbleDown(int i) {
    //Find the index of the larger child
    int maxIdx = findMax(2*i + 1, 2*i + 2);

    //Create tmp variable to hold current parent
    string tmpParent = heap[i];

    //Only run if the parent had children
    if(maxIdx != -1){
        //Create tmp variable to hold current larger child
        string tmpChild = heap[maxIdx];

        //If the value at the index is less than the value of the greatest child
        if(tmpParent < tmpChild){
            heap[i] = tmpChild;
            heap[maxIdx] = tmpParent;

            bubbleDown(maxIdx);
        }
    }
}

/* ********* Part 2 ********* */
string BinHeap::deleteHeap2() {
	/* here – look at the .hpp for a description of the method that goes here */
    string val = heap[0];

    heap[0] = heap[heaplen - 1];
    heaplen--;

    heap[arrlen - (arrlen-heaplen)] = val;

    bubbleDown(0);

    return val;

}

/* finally, this method is simple – it loops the length of the heap, and calls deleteHeap2() method that many times, in
 essence deleting all the values from the heap. The only gotcha in this one is that deleteHeap2() modifies the heaplen
 property, so you will need a temporary variable in this method that gets set to the heaplen before the loop and then
 resets heaplen to that value after the loop. Otherwise the heaplen value will be changing as you are looping and it
 gets a bit crazy */
void BinHeap::deleteAll() {
	/* here – look at the .hpp for a description of the method that goes here */
    int tmpHeaplen = heaplen;

    for(int i = 0; i < tmpHeaplen; i++){
        deleteHeap2();
    }

    heaplen = tmpHeaplen;
}



