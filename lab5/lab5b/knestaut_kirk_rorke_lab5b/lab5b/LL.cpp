/*
 * LL.cpp
 *
 *  Nov 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rouke
 */

#include "LL.hpp"
#include "BSTY.hpp"

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

LL::LL(){
	first = NULL;
	last = NULL;
	size = 0;
	score = 0;
}

void LL::push(string c){
	SNodeL *temp = new SNodeL(c);

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

void LL::addFirst(string c){
	SNodeL *temp = new SNodeL(c);

	first = temp;
	last = temp;
	size = 1;
}

void LL::printList(){
	SNodeL *curr = first;
		while(curr != NULL){
			curr->printNode();
			curr = curr->next;
		}
		cout << "" << endl;
}

/*
void LL::getScore(){
	SNodeL *curr = first;

	for(int i = 0; i < size; i++){
		if(find(curr) == NULL){
			score = score + 0; //could not find the word
		}
		else{
			score++;
		}
	}
}
*/

LL::~LL(){
	cout << "deleted each node" << endl;
}

