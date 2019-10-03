/*
 * ticTacToe.hpp
 *
 *  Sept 19, 2019
 *      Author: Aaron Knestaut and Dylan Kirk
 */

#ifndef TICTACTOE_HPP_
#define TICTACTOE_HPP_
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

class ticTacToe{
	char **board;
	string p1Name;
	string p2Name;
	char turn;

public:
	ticTacToe(string x, string o);
	void initial();
	void printBoard();
	bool boardFull();
	bool checkWin(char p);
	void personPlay();
	void playGame();

	~ticTacToe();

};



#endif /* TICTACTOE_HPP_ */
