/*
 * lab4a.cpp
 *
 * Oct 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include "book.hpp"

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void printGreatest(Book* array);


/*
 * Prints out the book with the highest rating from the array
 */
void printGreatest(Book* array){
	Book great = array[0];
	for(int i = 1; i < 4; i++){
		if(array[i].avgRating() > great.avgRating()){
			great = array[i];
		}
	}
	cout << "The book with the greatest rating is: " << endl;
	great.printInfo();
}

int main(){
	int bookRate1[10] = {1,5,2,7,6,4,9,10,4,3};
	int bookRate2[10] = {1,2,3,4,1,2,1,2,2,2};
	int bookRate3[10] = {10,10,10,10,10,10,10,10,10,10};
	int bookRate4[10] = {6,7,4,2,0,0,1,5,7,3};
	int bookRate5[10] = {1,1,1,1,1,1,1,1,1,1};
	Book book1 = Book("Dylan", "Kirk", "Monster Hunter", 2007, bookRate1);
	Book book2 = Book("Aaron", "Knestaut", "Destiny", 2012, bookRate2);
	Book book3 = Book("Peter", "Parker", "Spiderman", 2013, bookRate3);
	Book book4 = Book("Donkey", "Kong", "Bananas: A Cookbook", 2009, bookRate4);
	Book book5 = Book("Samus", "Aran", "How to Hunt Space Pirates", 2002, bookRate5);
	Book shelf[5] = {book1, book2, book3, book4, book5};

	printGreatest(shelf);


	Book* heapBook;
	heapBook = new Book("Sonic", "Hedgehog", "My Fanfic", 2010);
	heapBook->printInfo();

	Book* heapBook2;
	heapBook2 = new Book("Kirby", "", "Poyo", 2000);
	Book *heapShelf[2] = {heapBook, heapBook2};

	heapShelf[0]->printInfo();
	heapShelf[1]->printInfo();
}

