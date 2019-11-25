/*
 * SNodeL.hpp
 *
 *  Nov 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rouke
 */

#ifndef SNODEL_HPP_
#define SNODEL_HPP_

#include <iostream>
using namespace std;

class SNodeL {
          friend class LL;
          friend class Game;
          string word;
          SNodeL *next;

public:
	  SNodeL(string word);
	  ~SNodeL();
	  void printNode();

};


#endif /* SNODEL_HPP_ */
