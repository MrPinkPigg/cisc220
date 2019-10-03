/*
 * main.cpp
 *
 *      Due: Sept 5, 2019
 *      Author: Brandon Dongfack, Aaron Knestaut
 *			    Dylan Kirk, Joel Hafycz
 *
 * contains all 11 questions of lab 1
 */

#include <iostream>
using namespace std;

/*
 * function declarations
 */
void stars();
bool prime(int);
void sum();
int numbers();
void table(int);
void multable();
void leapYear();
int collatz();
void drawX(int);
void collatz2(int a, int b);

/*
 * main function
 *
 * no parameters
 * returns:
 * 		an integer
 *
 * the main function that runs and tests all other problems
 */
int main() {
	//problem 1
	cout << "Hello world" << endl;

	//problem 2
	stars();

	//problem 3
	//prime(3) -> true
	//prime(5) -> true
	//prime(8) -> false
	prime(3);
	prime(5);
	prime(8);
	stars();

	//problem 4
	sum();
	stars();

	//problem 5
	cout << numbers() << endl;
	stars();

	//problem 6
	//table(1) -> 1 2 3 4 5 6 7 8 9 10 11 12
	//table(2) -> 2 4 6  8 10 12 14 16 18 20 22 24
	//table(4) -> 4 8 12 16 20 24 28 32 36 40 44 48
	table(1);
	cout << "" << endl;
	table(2);
	cout << "" << endl;
	table(4);
	stars();

	//problem 7
	multable();
	stars();

	//problem 8
	//input 1 -> output 0
	//input 2 -> output 1
	//input 7 -> output 16
	cout << collatz() << endl;
	cout << collatz() << endl;
	cout << collatz() << endl;
	stars();

	//problem 9
	leapYear();
	stars();

	//problem 10
	//drawX(3) -> prints an x with 3 stars per leg
	//drawX(5) -> prints an x with 5 stars per leg
	//drawX(7) -> prints an x with 7 stars per leg
    drawX(3);
	drawX(5);
	drawX(7);
	stars();

	//problem 11
	//collatz2(1, 4) -> 2, 3
	//collatz2(2, 4) -> 3
	//collatz2(1, 5) -> 2, 3, 4
	collatz2(1, 4);
	collatz2(2, 4);
	collatz2(1, 5);

	return 1;
}

/*
 * problem 2
 * no parameters
 * returns:
 * 		void
 *
 * prints a line of stars in the console, used to separate every question's output
 */
void stars() {
	cout << "***********" << endl;
}

/*
 * problem 3
 * parameters:
 * 		int num - an input number from main
 * returns:
 * 		a boolean
 *
 * takes in a number and returns true or false depending on if the number is prime
 */
bool prime(int num) {
	int count = 2;
	while(count < num){
		if(num%count == 0){
			//cout<<num<<" is not prime"<<endl;
			return false;
		}
		else{
			count++;
		}
	}
	//cout<<num<<" is prime"<<endl;
	return true;
}

/*
 * problem 4
 * no parameters
 * returns:
 * 		void
 *
 * calculates the sum of every number from 1 to 300. Prints
 * the current sum every 20 terms
 */
void sum() {
	int num = 0;
	for (int i=1; i<=300; i++) {
		num = i + num;
		if (num%20 == 0) {
			cout << num << endl;
		}
	}
}

/*
 * problem 5
 * no parameters
 * returns:
 * 		an integer
 *
 * prints the number of values in the sum between 1 and infinity
 * after the sum is greater than 100000
 */
int numbers() {
	int num = 0;
	int count = 0;
	while(num < 100000){
		num += count;
		count++;
	}

	return count;
}

/*
 * problem 6
 * parameters:
 * 		int num - an input of a number from main
 * returns:
 * 		void
 *
 * takes in a number and prints out that number's multiplication
 * tables from 1 to 12
 */
void table(int num) {
	for (int i=1; i<13; i++) {
		int table = num * i;
		cout << table << endl;
		}
}

/*
 * problem 7
 * no parameters
 * returns:
 * 		void
 *
 * prints the multiplication tables for every number
 * from 1 to 12 by using table()
 */
void multable() {
	for (int i=1; i<13; i++) {
		for (int j=1; j<13; j++) {
			int table = i * j;
			cout << table << endl;
		}
	}
}

/*
 * problem 8
 * no parameters
 * returns:
 * 		an integer
 *
 * uses the collatz conjecture to reduce an input number to 1,
 * then prints how many times the loop had to run to get that number to 1
 */
int collatz(){
	int x;
	int count = 0;
	cout << "Enter a positive natural number" << endl;
	cin >> x;

	while(x > 1){
		if(x%2 == 0){
			x=x/2;
			count++;
		}
		else{
			x = x * 3;
			x = x + 1;
			count++;
		}
	}

	return count;
}

/*
 * problem 9
 * no parameters
 * returns:
 * 		void
 *
 * staring at 2017, prints out the leap years for
 * the next 400 years
 */
void leapYear(){
	int year = 2017;
	int maxYear = 2017 + 400;
	int rule = 1;
	while(year <= maxYear){
		//step 1
		if(rule == 1){
			if(year%4 == 0){
				rule = 2;
			}
			else{
				rule = 5;
			}
		}
		//step 2
		else if(rule == 2){
			if(year%100 == 0){
				rule = 3;
			}
			else{
				rule = 4;
			}
		}
		//step 3
		else if(rule == 3){
			if(year%400 == 0){
				rule = 4;
			}
			else{
				rule = 5;
			}
		}
		//step 4
		else if(rule == 4){
			cout << year << endl;
			year++;
			rule = 1;
		}
		//step 5
		else{
			year++;
			rule = 1;
		}
	}
}

/*
 * problem 10
 * parameters:
 * 		int size - a number input from main for the size of the X
 * returns:
 * 		void
 *
 * takes in a number for the size of one leg of the X
 * then prints that X usinging stars
 */
void drawX(int size){
	if(size % 2 == 0){
		size += 1;
	}
	int line = ((size * 2) - 1);

	for(int i = 0; i < line; i++){
		for(int j = 0; j <= line; j++){
			if(i == j || (j + i == line - 1)){
				cout << "*";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
}


/*
 * problem 11
 * parameters:
 * 		int a - a number from main
 * 		int b - a number from main, larger than int a
 * returns:
 * 		void
 *
 * every number between a and b is printed out and tested against
 * the collatz conjecture
 */
void collatz2(int a, int b) {
	a++;
	for (; a < b; a++) {
		int c = a;
		cout << a << endl;
		while(a > 1){
				if(a%2 == 0){
					a=a/2;
				}
				else {
					a = a * 3;
					a = a + 1;
				}
			}
		cout << "Collatz Conjecture is still working" << endl;
		a = c;
	}
}
