/*
 * lab3-3_4.cpp
 *
 *  Sept 19, 2019
 *      Author: Aaron Knestaut and Dylan Kirk
 */
#include "ticTacToe.hpp"
#include "Box.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

int main(){
	string px;
	string po;

	cout << "player X's name:" << endl;
	cin >> px;
	cout << "player O's name:" << endl;
		cin >> po;

	ticTacToe g(px, po);
	g.playGame();

	Box Box1(3.3, 1.2, 1.5);
	Box Box2(8.5, 6.0, 2.0);
	Box Box3 = Box1 + Box2;
	Box Box4(2.2, 2.2, 2.2);
	Box Box5(2.2, 2.2, 2.2);

	double volume = Box3.getVolume();
	cout << "Vol. of Box3 : " << volume <<endl;
	if(Box1 == Box2){
		cout << "These boxes are equal" << endl;
	}
	else{
		cout << "These boxes are not equal" << endl;
	}

	if(Box4 == Box5){
		cout << "These boxes are equal" << endl;
	}
	else{
		cout << "These boxes are not equal" << endl;
		return 0;
	}
}



