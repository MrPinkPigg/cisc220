/*
 * SNode.cpp
 *
 *  Oct 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include "SNode.hpp";

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
 * default SNode constructor
 *
 * no parameters
 *
 * asks the user for the rating and their comments, and creates a new node
 */
SNode::SNode(){
	rating = 0;

	cout << "Enter your rating: " << endl;
	cin >> rating;

	cout << "Enter your comments: " << endl;
	cin >> comments;

	next = NULL;
}

/*
 * SNode constructor
 *
 * parameters:
 * 		int r - an input rating
 * 		string c - an input comment
 *
 * takes in a rating and comment and makes a new node
 */
SNode::SNode(int r, string c){
	rating = r;
	comments = c;
	next = NULL;
}

/*
 * printNode
 *
 * no parameters
 * returns:
 * 		void
 *
 * prints out the rating and comment associated with a node
 */
void SNode::printNode(){
	cout << "Rating: " << rating << " Comments: " << comments << endl;
}

/*
 * destructor
 */
SNode::~SNode(){
	cout << "deleting: " << rating << ", " << comments << endl;
}

