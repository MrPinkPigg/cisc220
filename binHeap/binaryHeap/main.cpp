/*
 * main.cpp
 *
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include "BinHeap.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {
	/*for testing insertHeap*/
    string arr4[] = {"h","u","i","x","tun","na","c","n"};
    BinHeap *h4 = new BinHeap(arr4,8);
    	//yep, it's a word!! Google it with the word ghost!
    cout << "What does the above word mean (google it with the word 'ghost')?" << endl;
    cout << "***************************************" << endl;
    delete h4;

/**************************************************/
    /* for testing deleteHeap() */
    string arr[] = {"mhai", "ho", "i", "nop", "a", "za", "th", "y", "sa", "b" };
    BinHeap *h = new BinHeap(arr,10);
    h->deleteHeap();
    h->deleteHeap();
    h->deleteHeap();
    h->printHeap();
    cout << "What does the above word mean? (this is a good one!)" << endl;
    cout << "***************************************" << endl;
    delete h;

/**************************************************/
    /* for deleteHeap2() and deleteAll(): NOTE WHAT HAPPENS HERE!!*/

    string arr2[] = {"j","c","e","d","a","k","g","b","f","h","i"};
    BinHeap *h2 = new BinHeap(arr2,11);
    h2->deleteAll();
    cout <<"\nAfter: (Notice what happened here!!!!!)";
    h2->printHeap();
    cout << "**********************************"<<endl;
    delete h2;
    string arr3[] = {"l","ho","ko","ogic","ka","at","ag"};
    BinHeap *h3 = new BinHeap(arr3,7);

    h3->deleteAll();

    cout <<"\nAfter: deleteAll()";
    h3->printHeap();
    cout << "What does the above word mean?" << endl;
    cout << "**********************************"<<endl;
    delete h3;

    return 0;
}



