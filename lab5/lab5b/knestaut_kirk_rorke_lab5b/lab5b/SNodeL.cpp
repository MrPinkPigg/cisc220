/*
 * SNodeL.cpp
 *
 * Nov 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rouke
 */

#include "SNodeL.hpp"

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

SNodeL::SNodeL(string s){
	word = s;
	next = NULL;
}

void SNodeL::printNode(){
	cout << word << endl;
}

SNodeL::~SNodeL(){

}


