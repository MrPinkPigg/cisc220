/*
 * SLL.cpp
 *
 *  Oct 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include "SLL.hpp";

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
 * SLL Constructor
 *
 * no parameters
 *
 * makes a new singly linked list
 */
SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}

/*
 * printSLL()
 *
 * no paramters
 * returns:
 * 		void
 *
 * prints out a singly linked list of nodes
 */
void SLL::printSLL(){
	SNode *curr = first;
	while(curr != NULL){
		curr->printNode();
		curr = curr->next;
	}
	cout << "" << endl;
}

/*
 * insertInOrder()
 *
 * parameters:
 * 		int r - an input rating
 * 		string c - an input comment
 * returns:
 * 		void
 *
 * correctly adds a new node into the list, in order
 */
void SLL::insertInOrder(int r, string c){
	SNode *temp = new SNode(r, c);
	SNode *curr = first;

	if(size == 0){
		addFirst(r, c);
	}
	else if(temp->rating <= first->rating){
		addAtFront(r, c);
	}
	else if(temp->rating >= last->rating){
		push(r, c);
	}
	else{
		for(int i = 0; i < size; i++){
			if((temp->rating >= curr->rating) && (temp->rating <= curr->next->rating)){
				temp->next = curr->next;
				curr->next = temp;
				size++;
				break;
			}
			else{
				curr = curr->next;
			}
		}
	}
}

/*
 * push()
 *
 * parameters:
 * 		int r - an input rating
 * 		string c - an input comment
 * returns:
 * 		void
 *
 * pushes a new node onto the end of the list
 */
void SLL::push(int r, string c){
	SNode *temp = new SNode(r, c);

	if(size == 0){
		first = temp;
		last = temp;
		size++;
	}
	else{
		last->next = temp;
		last = temp;
		size++;
	}
}

/*
 * addAtFront()
 *
 * parameters:
 * 		int r - an input rating
 * 		string c - an input comment
 * returns:
 * 		void
 *
 * adds a new node to the front of the list
 */
void SLL::addAtFront(int r, string c){
	SNode *temp = new SNode(r, c);

	if(size == 0){
		first = temp;
		last = temp;
		size++;
	}
	else{
		temp->next = first;
		first = temp;
		size++;
	}
}

/*
 * addFirst()
 *
 * parameters:
 * 		int r - an input rating
 * 		string c - an input comment
 * returns:
 * 		void
 *
 * adds the first node to an empty list
 */
void SLL::addFirst(int r, string c){
	SNode *temp = new SNode(r, c);

	first = temp;
	last = temp;
	size = 1;
}

/*
 * pop()
 *
 * no parameters
 * returns:
 * 		an int
 *
 * removes and returns the rating from the last item from the list
 */
int SLL::pop(){
	SNode *temp = last;
	SNode *curr = first;

	for(int i = 0; i < size; i++){
		if(curr->next == last){
			last = curr;
			curr->next = NULL;
		}
		else{
			curr = curr->next;
		}

	}

	return temp->rating;

}

/*
 * getAve()
 *
 * no parameters
 * returns:
 * 		double
 *
 * returns the average of all the ratings in a list
 */
double SLL::getAve(){
	double total = 0;
	SNode *curr = first;
	for(int i = 0; i < size; i++){
		total += curr->rating;
		curr = curr->next;
	}
	return total/size;
}

/*
 * destructor
 */
SLL::~SLL(){
	cout << "deleted each node" << endl;
}
