/*
 * Box.hpp
 *
 *  Sept 19, 2019
 *      Author: Aaron Knestaut and Dylan Kirk
 */

#include <iostream>
#include <stdlib.h>

#ifndef BOX_HPP_
#define BOX_HPP_

class Box {
 double length;
 double breadth;
 double height;
 public:
 Box(double l, double b, double);
 double getVolume();
 Box operator+(Box b);
 bool operator==(Box b2);
};




#endif /* BOX_HPP_ */
