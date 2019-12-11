/*
 * hashNode.cpp
 *
 * Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hashNode.hpp"

using namespace std;

/**
 * initializes a default hashnode
 */
hashNode::hashNode(){
	keyword = "";
	valuesSize = 0;
	currSize = 0;
	values = NULL;
}

/**
 * initializes a hashnode with a keyword, and dynamically built array
 */
hashNode::hashNode(string s){
	keyword = s;
	valuesSize = 100;
	currSize = 0;
	values = new string[valuesSize];
}

/*
 * initializes a hashnode with a keyword, a dynamically built array, and a value attached to the key
 */
hashNode::hashNode(string s, string v){
	keyword = s;
	valuesSize = 100;
	currSize = 1;
	values = new string[valuesSize];
	values[0] = v;
}

/**
 * adds a value to the end of the hashnode, then checks if the array length needs to be increased
 */
void hashNode::addValue(string v){
	values[currSize] = v;
	currSize++;
	if(currSize >= valuesSize){ dblArray(); }
}

/**
 * creates a new array of double the size, and copies over the old values
 */
void hashNode::dblArray(){
	string *newArray = new string[valuesSize * 2];
	for(int i = 0; i < valuesSize; i++){
		newArray[i] = values[i];
	}
	valuesSize = valuesSize*2;
	values = newArray;
}

/*
 * returns a random string from the value array, or an empty string
 */
string hashNode::getRandValue(){
    if(currSize == 0) {
        return "";
    } else {
    	int randVal = rand()%currSize;
        return values[randVal];
    }
}
