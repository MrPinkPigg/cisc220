/*
 * book.cpp
 *
 * Oct 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Oliva Rorke
 */

#include "book.hpp"

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
 * Book constructor that initializes all ratings to 0
 */
Book::Book(string first, string last, string bookName, int bookYear){
	authorFirst = first;
	authorLast = last;
	name = bookName;
	year = bookYear;
	for(int i = 0; i < 10; i++){
		ratings[i] = 0;
	}
}

/*
 * Book constructor that takes in an array of ratings
 */
Book::Book(string first, string last, string bookName, int bookYear, int *bookRatings){
	authorFirst = first;
	authorLast = last;
	name = bookName;
	year = bookYear;
	for(int i = 0; i < 10; i++){
		ratings[i] = bookRatings[i];
	}
}

/*
 * finds the average of a books ratings
 */
double Book::avgRating(){
	double avg = 0;

	for(int i = 0; i < 10; i++){
		avg = avg + ratings[i];
	}
	avg = avg / 10;

	return avg;
}

/*
 * prints the average rating of a book
 */
void Book::printRating(){
	double avg = avgRating();

	if(avg == 0){
		cout << "This book has not yet been rated" << endl << endl;
	}
	else{
		cout << "This book's rating is: " << avg << endl << endl;
	}
}

/*
 *prints out all of the book's information
 */
void Book::printInfo(){
	cout << "Author: " << authorFirst << " " << authorLast << endl;
	cout << "Title: " << name << endl;
	cout << "Year: " << year << endl;
	printRating();
}


/*
 * overloads the > operator to compare the average ratings of books
 */
bool Book::operator>(Book b){
	if(avgRating() > b.avgRating()){
		return true;
	}
	else{
		return false;
	}
}

/*
 * destructor
 *
 * prevents memory leaks
 */
Book::~Book(){
	delete [] ratings;

	//cout << "Rating array destroyed" << endl;
}
