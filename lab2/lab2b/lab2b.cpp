/*
 * Lab2b.cpp
 *
 * Sept 12, 2019
 *      Author: Joel Hafycz, Aaron Knestaut,
 *      		Dylan Kirk, Brandon Dongfack
 */

//#include "lab2b.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main();
void stars();
void randarr(int a, int &b);
void reverse(int len);
void printArr(int*, int);
void smallarr(int a, int b);
void printDoub(double*, int);
void printInt(int*, int);
int* stackNum();
int *bigarr(int *a, int *b, int *c);
int twoDArr(int* x, int* y);
void printGraph(int arr[], int m, int n, int o);
int arrayFilter(int arr[], int arraySize);
int hann(int arr[]);

int main() {
	//problem 1
	int b = 2;
	randarr(5, b);
	cout << b << endl;
	stars();

	//problem 2
	reverse(5);
	reverse(9);
	stars();


	//problem 3
	smallarr(5, 50);
	stars();


	//problem 4
	int *p4 = stackNum();
	cout << p4 << endl;
	cout << &p4 << endl;
	/*
	 * the program compiles, but main does not output
	 * the correct values, for either the address or the value.
	 */
	stars();

	//problem 5
	int test[25];
	srand(time(NULL));
	for(int i = 0; i < 25; i++){
		test[i] = (rand()%10) + 1;
		}
	printArr(test, 25);
	stars();


	//problem 6
	int m = 3;
	int n = 4;
	int o = 5;
	int *k = &m;
	int *j = &n;
	int *l = &o;
	int *arr= bigarr(k,j,l);

	//printArr(arr, m);
	stars();

	//problem 7


	//problem 8
	int test3[] = {2, 3, 4};
	int length2 = *(&test3 + 1) - test3;
	printInt(test3, length2);
	stars();


	//problem 9
	double test2[] = {2.1, 3.0, 5.55};
	int length = *(&test2 + 1) - test2;
	printDoub(test2, length);
	stars();

	//problem 10


	//problem 11


	//problem 12
	//int *p12arr = arrayFilter(p11arr, 10, 3);
	//printArr(p12arr, 10);
	//p12arr = arrayFilter(p11arr, 10, 5);
	//printArr(p12arr, 10);

	//problem 13
	printArr(arr, m);
	printGraph(arr, m, n, o);
	delete []arr;

	//problem 14
	int px14;
	int py14;
	//int **arr14 = twoDArr(&px14, &py14);
	for(int i = 0; i < px14; i++){
		//printArr(arr14[i], py14)
	}
}

//Just used to break up each problem's output
void stars() {
	cout << "**********" << endl;
}

/* Problem 1
 *
 * parameters: int (length)
 * 			   int (modified)
 *
 * returns: void
 *
 * Second parameter = -1
 * Generate random array of length
 * Sets the second parameter to the smallest in the array
 */
void randarr(int len, int &mod) {
	mod = -1;
	int arr[len];
	srand(time(NULL));
	for (int i=0; i<len; i++){
		arr[i] = rand()%50;
		cout << arr[i] << ",";
	}
	cout << endl;
	int a = 50;
	for (int i=0; i<len; i++){
		if (a > arr[i]) {
			a = arr[i];
		}
	}
	mod = a;
	cout << a << endl;
}


/*
 * problem 2
 *
 *  parameters:
 *  	int- length
 *  returns:
 *  	void
 *
 *  creates an array of length len and fills it with random numbers between 0 and 50,
 *  then reverses the order of the array so the last element becomes the first, and so on
 */

void reverse(int len){
	int arr[len];
	srand(time(NULL));
	for(int i = 0; i < len; i++){
		arr[i] = rand()%50;
		cout << arr[i] << ", ";
	}
	cout << endl;

	for(int j = 0; j < len/2; j++){
		int temp = arr[j];
		arr[j] = arr[(len - 1) - j];
		arr[(len - 1) - j] = temp;
	}

	for(int k = 0; k < len; k++){
		cout << arr[k] << ", ";
	}
	cout << endl;
}


/*
 * problem 3
 *
 * parameters: int (length)
 * 			   int (range)
 *
 * returns: void
 *
 * Creates an array of length and range
 * and prints each int from smallest to greatest
 * then changes them to the range +1
 */

void smallarr(int len, int range) {
	int count = len;
	int arr[len];
	srand(time(NULL));
	for (int i=0; i<len; i++){
		arr[i] = rand()%range;
		cout << arr[i] << ",";
	}
	cout << endl;
	int a = 10000;
	int x;
	while (count > 0) {
		for (int i=0; i<len; i++) {
			if (a > arr[i]) {
				a = arr[i];
				x = i;
			}
		}
		arr[x] = range + 1;
		cout << a << ",";
		a = 10000;
		count--;
	}
	cout << endl;
	for (int i=0; i<len; i++){
		cout << arr[i] << ",";
	}
	cout << endl;
}

/*
 * problem 4
 *
 * no parameters
 * returns:
 * 		int*
 *
 * sets integer p4 to 3, then returns the address of that int
 */
int* stackNum(){
	int p4 = 3;
	cout << p4 << endl;
	cout << &p4 << endl;

	return &p4;
}

/*
 * problem 5
 *
 *  parameters:
 *  	int- array
 *  	int- size
 *  retruns:
 *  	void
 *
 *  prints out a given array on a single line
 *  takes the size of the array as a seperate parameter
 */

void printArr(int *arr, int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}


/*
 * problem 6
 *
 * parameters: 3 ints (pointer)
 *
 * returns: an array
 *
 * inputs 3 values and
 */

int *bigarr(int *a, int *b, int *c) {
	srand(time(NULL));
	int len = rand()%25 + 25;
	int high = rand()%5 + 5;
	int low = rand()%5 - 10;
	int arr[len];
	for (int i=0; low < high; i++, low++){
		arr[i] = low;
	}
	*a = len;
	*b = high;
	*c = low;
	return arr;
}


/*
 * problem 7
 */


/*
 * problem 8
 *
 *parameters: array of int (and size)
 *
 *return: void
 *
 *prints address of every value in the array
 */
void printInt(int *array, int length){
	for(int i = 0; i < length; i++){
		cout << &array[i] << ", ";
	}
	cout << endl;
}


/*
 * problem 9
 *
 * parameters:
 * 		double- arr
 * 	returns:
 * 		void
 *
 * 	takes in an array of doubles and prints the address of each element in the array
 */

void printDoub(double *array, int length){
	for(int i = 0; i < length; i++){
		cout << &array[i] << ", ";
	}
	cout << endl;
}


/*
 * problem 10
 */
/*int removeDubNum(int array[], int *size){
	int newArray = new int[*size];
	for (int i = 0; i < *size; i++){
		if(array[i] == array[i+1]){
			int x = 0;
			newArray[i] = newArray[x];
			i++;
			x++;
		}
		else {
			newArray[i] = newArray[x];
			x++;
		}
	}
	return newArray;
}
*/
/*
 * problem 11
 */
int hann(int array[]){
	int windowsize;
	int weight;
	int averageweight;
	for (int i = 0; i < windowsize; i++){
		if (i < (windowsize/2)){
			weight = i +1;

		}
		else {
			weight = windowsize - i;
		}
		averageweight = averageweight + (array[i]*weight);
	}
		return averageweight;
}


/*
 * problem 12
 */
//int arrayFilter(int array[], int arraySize){
//	int newArray = new int[arraySize];
//	for (int i =0; i < arraySize; i++){
//		newArray[i] = hann(&array[i]);
//	}
//
//
//	return newArray;
//}


/*
 * problem 13
 */
void printGraph(int arr[], int len, int highVal, int lowVal){
	for(int i = highVal; i >= lowVal; i--){
		if(i >= 0){
			cout << " ";
		}
		cout << i << ":";
		for(int k = 0; k < len; k++){
			if(arr[k] == i){
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
 * problem 14
 */
/*int **twoDArr(int *x, int *y){
	srand(time(NULL));
	*x = rand()%10 + 5;
	*y = rand()%8 + 4;
	int **arr = NULL;
	arr = new int *[*x];
	for(int i = 0; i < *x; i++){
		arr[i] = new int[*y];
	}
	for(int k = 0; k < *x; k++){
		for(int j = 0; j < *y; j++){
			arr[k][j] = 0;
		}
	}
	for(int n = 0; n < 5; n++){
		arr[rand()%*x][rand()%*y] = 1;
	}
	return arr;
}
*/

