/*
 * ticTacToe.cpp
 *
 *  Sept 19, 2019
 *      Author: Aaron Knestaut and Dylan Kirk
 */

#include "ticTacToe.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

/*
 * ticTacToe constructor
 *
 * parameters:
 * 		string x - player x name
 * 		string o - player o name
 *
 * creates a new board, and sets the player's names
 */
ticTacToe::ticTacToe(string x, string o){
	p1Name = x;
	p2Name = o;
	board = new char *[3];
	for(int i = 0; i < 3; i++){
		board[i] = new char [3];
	}
	turn = 'X';

	initial();
}

/*
 * initial()
 *
 * no parameters
 * returns:
 * 		void
 *
 * initializes the board by setting every spot to '_'
 */
void ticTacToe::initial(){
	for(int i = 0; i < 3; i++){
		for(int k = 0; k < 3; k++){
			board[i][k] = '_';
		}
	}
}

/*
 * printBoard()
 *
 * no parameters
 * returns:
 * 		void
 *
 * prints out the whole board
 */
void ticTacToe::printBoard(){
	cout << board[0][0] << "\t" << board[0][1] << "\t" << board[0][2] << endl;
	cout << board[1][0] << "\t" << board[1][1] << "\t" << board[1][2] << endl;
	cout << board[2][0] << "\t" << board[2][1] << "\t" << board[2][2] << endl;
}

/*
 * boardFull()
 *
 * no parameters
 * returns:
 * 		boolean
 *
 * determines if the entire board is full
 */
bool ticTacToe::boardFull(){
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 3; k++){
				if(board[i][k] == '_'){
					return false;
				}
			}
		}

		return true;
}

/*
 * checkWin()
 *
 * parameters:
 * 		char p - one of the players
 * returns:
 * 		boolean
 *
 * checks the board for if one of the players has won
 */
bool ticTacToe::checkWin(char p){

	//i got lazy lol
	//horizontal
	if((board[0][0] == p ) && (board[0][1] == p) && (board[0][2] == p)){
		return true;
	}
	else if((board[1][0] == p) && (board[1][1] == p) && (board[1][2] == p)){
		return true;
	}
	else if((board[2][0] == p) && (board[2][1] == p) && (board[2][2] == p)){
		return true;
	}
	//vertical
	else if((board[0][0] == p) && (board[1][0] == p) && (board[2][0] == p)){
		return true;
	}
	else if((board[0][1] == p) && (board[1][1] == p) && (board[2][1] == p)){
		return true;
	}
	else if((board[0][2] == p) && (board[1][2] == p) && (board[2][2] == p)){
		return true;
	}
	//left diagonal
	else if((board[0][0] == p) && (board[1][1] == p) && (board[2][2] == p)){
		return true;
	}
	//right diagonal
	else if((board[0][2] == p) && (board[1][1] == p) && (board[2][0] == p)){
		return true;
	}
	else{
		if(turn == 'X'){
			turn = 'O';
		}
		else{
			turn = 'X';
		}
		return false;
	}
}

/*
 * personPlay()
 *
 * no parameters
 * returns:
 * 		void
 *
 * takes in input from a player so they can make their turn
 */
void ticTacToe::personPlay(){
	bool done = false;
	int row;
	int col;

	while(!done){
		if(turn == 'X'){
			cout << p1Name << "'s turn" << endl;
			cout << "row (1, 2 or 3):" << endl;
			cin >> row;
			row--;
			cout << "column (1, 2 or 3):" << endl;
			cin >> col;
			col--;

			if(board[row][col] == '_'){
				board[row][col] = 'X';
				done = true;
			}
			else{
				cout << "That spot is taken already" << endl;
			}
		}
		else{
			cout << p2Name << "'s turn" << endl;
			cout << "row (1, 2 or 3):" << endl;
			cin >> row;
			row--;
			cout << "column (1, 2 or 3):" << endl;
			cin >> col;
			col--;

			if(board[row][col] == '_'){
			board[row][col] = 'O';
			done = true;
			}
			else{
				cout << "That spot is taken already" << endl;
			}
		}
	}

	printBoard();
}

/*
 * playGame()
 *
 * no parameters
 * returns:
 * 		void
 *
 * the main game class, that loops through all other functions
 * until the end of the game
 */
void ticTacToe::playGame(){
	printBoard();

	while(!boardFull()){
		personPlay();

		if(checkWin(turn)){
			if(turn == 'X'){
				cout << p1Name << " wins!" << endl;
				break;
			}
			else{
				cout << p2Name << " wins!" << endl;
				break;
			}
		}
	}

	if(boardFull()){
		cout << "The board is full. It's a tie!" << endl;
	}
}

/*
 * destructor
 *
 * used to prevent memory leaks
 */
ticTacToe::~ticTacToe(){
	for(int i = 0; i < 3; i++){
		delete [] board[i];
	}

	delete [] board;

	cout << "board destroyed" << endl;
}
