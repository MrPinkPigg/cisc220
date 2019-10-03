/*
 * Box.cpp
 *
 *  Sept 19, 2019
 *      Author: Aaron Knestaut and Dylan Kirk
 */

#include"Box.hpp"

#include <iostream>
#include <stdlib.h>

// Copied from lab instructions
Box::Box(double l, double b, double h) {
 length = l;
 breadth = b;
 height = h;
}
double Box::getVolume() {
 return length * breadth * height;
}

Box Box::operator+(Box b) { //Overload: add 2 Box objects.
 Box nBox(0,0,0);
 nBox.length = length + b.length;
 nBox.breadth = breadth + b.breadth;
 nBox.height = height + b.height;
 return nBox;
}


/*
 * overload ==
 *
 * parameters:
 * 	Box b2
 * returns:
 * 	bool
 *
 *  compares two boxes and returns true if all the parameters are equal and
 *  returns false if any on the parameters are not equal
 */

bool Box::operator==(Box b2){
	if((length == b2.length) && (breadth == b2.breadth) && (height == b2.height)){
		return true;
	}
	else{
		return false;
	}


}


