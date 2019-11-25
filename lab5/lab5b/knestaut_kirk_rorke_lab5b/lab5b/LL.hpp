/*
 * LL.hpp
 *
 * Nov 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rouke
 */

#ifndef LL_HPP_
#define LL_HPP_

#include "SNodeL.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class LL {
		  friend class Game;
          SNodeL *first;
          SNodeL *last;
          int size;
          int score;

public:
          LL();
          void push(string s);
          void addFirst(string s);
          void printList();
          void getScore();
          ~LL();
};




#endif /* LL_HPP_ */
