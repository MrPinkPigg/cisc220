/*
 * lab2a.cpp
 *
 *  Sept 12, 2019
 *      Author: Aaron Knestaut, Joel Hafycz,
 *              Brandon Dongfack, Dylan Kirk
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void print();
void add(int b);
int random();
void address(int &c);
void stars();
void addRand(int j);
void addInts(int *x, int *y);
bool swap(int &num1, int &num2);
void massSwap();
void callByMods(char a, char *b, char &c);

/*
 * main function
 *
 * no parameters
 * returns:
 * 		an int
 *
 * the main function that runs and tests all other problems
 */
int main () {
	//problem 1
	print();
	stars();

	//problem 2
	add(1);
	stars();

	//problem 3
	int k = random();
	cout << k << endl;
	cout << &k << endl;
	stars();

	//problem 4
	int i = 2;
	address(i);
	stars();

	//problem 5
	int j = 3;
	cout << j << endl;
	cout << &j << endl;
	addRand(j);
	cout << j << endl;
	cout << &j << endl;
	stars();

	//problem 6
	int zx = 10;

	int zxadvent = 20;
	addInts(&zx, &zxadvent);
	cout << zx << endl;
	cout << zxadvent << endl;
	stars();
	//problem 7
	char v = 's';
	char w = 'c';
	char x = 'o';
	char y = 'm';
	char z = 'i';
	cout << w << x << y << z << w << endl;
	callByMods(w, &x, y);
	cout << v << x << y << v << endl;
	stars();

	//problem 8a
	int p = 9;
	int q = 8;
	swap(q,p);
	swap(p,q);
	cout << "p is now " << p << endl;
	cout << "q is now " << q << endl;
	stars();

	//problem 8b
	massSwap();
	stars();
	return 1;
}

/*
 * stars
 *
 * no parameters
 * returns:
 * 		void
 *
 * used to separate the output of all the problems
 */
void stars() {
	cout << "**********" << endl;
}

/*
 * problem 1
 *
 * no parameters
 * returns:
 * 		void
 *
 * sets a = 3, then prints the value and memory address of a
 */
void print() {
	int a = 3;
	cout << a << endl;
	cout << &a << endl;
}

/*
 * problem 2
 *
 * parameters:
 * 		int b - a value passed in from main
 * returns:
 * 		void
 *
 * takes in a value and adds 4, then prints the new value and the memory address
 */
void add(int b) {
	b += 4;
	cout << b << endl;
	cout << &b << endl;
}

/*
 * problem 3
 *
 * no parameters
 * returns:
 * 		an int
 *
 * generates a random number and sets it to x, then prints the value
 * and its address, and returns the value
 */
int random() {
	srand(time(NULL));
	int x = rand()%50;
	cout << x << endl;
	cout << &x << endl;
	return x;
}

/*
 * problem 4
 *
 * parameters:
 * 		an int address
 * returns:
 * 		void
 *
 * takes in an integers address, and uses it to change the value
 * and print out the value and addresses of the value and parameter
 */
void address(int &c){
	c = c * c * c;
	cout << c << endl;
	cout << &c << endl;
	cout << &c << endl;
}


/*
 * problem 5
 *
 * parameters:
 * 		an int
 * 	returns:
 * 		void
 *
 * takes in an int and adds a random number 0-10 to it
 * and prints the random value, the new value, and the address of the input parameter
 */
void addRand(int d){
	srand(time(NULL));
	int num = rand()%11;
	d += num;
	cout << num << endl;
	cout << d << endl;
	cout << &d << endl;
}

/*
 * problem 6
 *
 * parameters:
 * 		two int addresses
 * returns: nothing (void)
 *
 * takes two addresses of ints and uses call by pointer to change the values of the ints
 * prints the new value of the ints
 */
void addInts(int *x, int *y){
	int *add = x;
	*add = 32;
	int *add2 = y;
	*add2 = 42;

}


/*
 * problem 7
 *
 * parameters:
 * 		char a
 * 		char b
 * 		char c
 * returns:
 * 		void
 *
 * takes in characters through call by value, pointer, and
 * reference to change those characters to print a new word
 */
void callByMods(char a, char *b, char &c){
	a = 's';
	*b = 'a';
	c = 'n';
}

/*
 * problem 8a
 *
 * parameters:
 * 		two int values
 * 	returns:
 * 		a boolean indicating if the two numbers were swapped
 *
 * 	takes in two integers and checks to see if the first is larger than the second
 * 	if the first is larger, the numbers are swapped and the function returns true
 * 	otherwise, nothing is swapped and the function returns false
 */
bool swap(int &num1, int &num2){
	if(num1 > num2){
		int temp = num1;
		num1 = num2;
		num2 = temp;
		return true;
	}
	else{
		cout << "nothing has changed" << endl;
		return false;
	}

}

/*
 * problem 8b
 *
 * 	parameters:
 * 		none
 * 	returns:
 * 		void
 *
 * 	generates 20 pairs on numbers between 0 and 25 and calls swap on each pair
 */
void massSwap(){
	srand(time(NULL));
	for(int i = 0; i < 20; i++){
		int rand1 = rand()%25;
		int rand2 = rand()%25;
		cout << rand1 << "   " << rand2 << endl;
		bool check = swap(rand1, rand2);
		if (check == true){
			cout << rand1 << "   " << rand2 << endl;
			cout << "The numbers were swapped" << endl;
		}
	}
}
