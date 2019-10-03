/*
 * book.hpp
 *
 * Oct 3, 2019
 *      Author: Aaron Knestaut, Dylan Kirk, Oliva Rorke
 */

#ifndef BOOK_HPP_
#define BOOK_HPP_

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Book{
	string authorFirst;
	string authorLast;
	int ratings[10];
	string name;
	int year;

public:
	Book(string first, string last, string bookName, int bookYear);
	Book(string first, string last, string bookName, int bookYear, int *bookRatings);
	double avgRating();
	void printRating();
	void printInfo();

bool operator>(Book book);

	~Book();
};


#endif /* BOOK_HPP_ */
