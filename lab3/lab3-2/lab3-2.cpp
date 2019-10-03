/*
 * lab3-2.cpp
 *
 *  Sept 19, 2019
 *      Author: Aaron Knestaut and Dylan Kirk
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

/*
 * class header
 */
class Hanning {
	int windowSize;
	int *originalArray;
	int arraySize;
	int *filteredArray;
	int origMax;
	int origMin;
	int filMax;
	int filMin;

	public:
		Hanning(int windowSize, int originalArray[], int arraySize, int filteredArray[]);
		int weightedAvg(int center[]);
		void filterArray();
		void printGraph(bool print);
		void newWinSize(int newSize);
		void printArray(bool print);
		void getHighAndLow();
}; //Hanning header

/*
 * constructor for the class
 * parameters:
 * 		int windowSize - the size of the hanning window
 * 		int originalArray[] - the original array to be filtered
 * 		int arraySize - the size of the original array
 * 		int filteredArray[] - the array to hold the filtered original array
 */
Hanning::Hanning(int x, int ogArr[], int y, int flArr[]){
	windowSize = x;
	originalArray = ogArr;
	arraySize = y;
	filteredArray = flArr;
	getHighAndLow();
}

/*
 * returns the weighted average of the original array
 *
 * parameters:
 * 		int center[] - the given array to find the average of
 * returns:
 * 		an int
 */
int Hanning::weightedAvg(int center[]){
    int windowRadius = windowSize / 2;
    int weighting = 1;
    int sum = 0;

    for(int i = 0; i < windowSize ; i++){
        sum += center[i] * weighting;

        if(i < windowRadius){
            weighting++;
        }else {
            weighting--;
        }
    }

    return sum / windowSize;

}

/*
 * uses weightedAvg() to filter the original array into filteredArray[]
 *
 * no parameters
 * returns:
 * 		void
 */
void Hanning::filterArray(){
	int windowRadius = windowSize / 2;

	for(int i = 0; i < arraySize; i++){
        if(i - windowRadius >= 0 && i + windowRadius <= arraySize - 1){
            filteredArray[i] = weightedAvg(&originalArray[i-windowRadius]);
        }else{
            filteredArray[i] = 0;
        }
    }
    getHighAndLow();
}

/*
 * prints the graph of either the original or filtered array
 *
 * parameters:
 * 		bool print - determines which array gets graphed
 * returns:
 * 		void
 */
void Hanning::printGraph(bool print){
	if(print == true){
	        for (int var = filMax; var >= filMin; var--) {
	            cout << var << ":";
	            for (int x=0; x < arraySize; x++) {
	                if (filteredArray[x] == var) {
	                    cout <<"*";
	                }
	                else {
	                    cout << " ";
	                }
	            }
	            cout << endl;
	        }
	    }

	    //Output an * at each occurence of a value within the original array
	    if(print == false){
	        for (int var = origMax; var >= origMin; var--) {
	            cout << var << ":";
	            for (int x=0; x < arraySize; x++) {
	                if (originalArray[x] == var) {
	                    cout <<"*";
	                }else {
	                    cout << " ";
	                }
	            }
	            cout << endl;
	        }
	    }
}

/*
 * sets a new window size, and corrects it if it is even.
 * then it reruns filterArray()
 *
 * parameters:
 * 		int newSize - the new window size
 * returns:
 * 		void
 */
void Hanning::newWinSize(int newSize){
	if(newSize%2 == 0){
		newSize--;
	}
	windowSize = newSize;
	filterArray();
}

/*
 * prints either the filtered or original array
 *
 * parameters:
 * 		bool print - determines which array gets printed
 * returns:
 * 		void
 */
void Hanning::printArray(bool print){
	if(print == false){
	        for (int x = 0; x < arraySize; x++) {
	            cout << originalArray[x] << ", ";
	        }
	        cout << endl;
	    }

	    if(print == true){
	        for (int x = 0; x < arraySize; x++) {
	            cout << filteredArray[x] << ", ";
	        }
	        cout << endl;
	    }
}

/*
 * determines what values to set to all 4 min/max variables
 *
 * no parameters
 * returns:
 * 		void
 */
void Hanning::getHighAndLow(){
    origMax = -100;
    origMin = 100;

    for(int i = 0; i < arraySize; i++){
        if(originalArray[i] > origMax){
            origMax = originalArray[i];
        }
        if(originalArray[i] < origMin){
            origMin = originalArray[i];
        }
    }

    filMax = -100;
    filMin = 100;

    for(int i = 0; i < arraySize; i++){
        if(filteredArray[i] > filMax){
            filMax = filteredArray[i];
        }
        if(filteredArray[i] < filMin){
            filMin = filteredArray[i];
        }
    }
}

/*
 * main function
 *
 * no parameters
 * returns:
 * 		an int
 *
 * creates and tests multiple Hanning instances
 */
int main(){
	//Create 2 arrays of the same size
	    int array1[15] = {2, 5, 8, 2, 9, 3, 4, 5, 1, 6, 3, 3, 5, 4, 5};
	    int array2[15] = {3, 9, 7, 3, 5, 2, 1, 6, 8, 3, 5, 5, 8, 2, 4};

	    //Create a new HanningWindow object with the 2 arrays
	    Hanning han(3, array1, 15, array2);

	    //Create a filtered array
	    han.filterArray();

	    //Print the original array
	    cout << "Original Array:" << endl;
	    han.printArray(false);
	    cout << endl;

	    //Print the filtered array
	    cout << "Filtered Array:" << endl;
	    han.printArray(true);
	    cout << endl;

	    //Graph the original array
	    cout << "Original Array:" << endl;
	    han.printGraph(false);
	    cout << endl;

	    //Graph the filtered array
	    cout << "Filtered Array:" << endl;
	    han.printGraph(true);
	    cout << endl;

	    //Change window size
	    han.newWinSize(5);

	    //Print the original array
	    cout << "Original Array:" << endl;
	    han.printArray(false);
	    cout << endl;

	    //Print the filtered array
	    cout << "Filtered Array:" << endl;
	    han.printArray(true);
	    cout << endl;

	    //Graph the original array
	    cout << "Original Array:" << endl;
	    han.printGraph(false);
	    cout << endl;

	    //Graph the filtered array
	    cout << "Filtered Array:" << endl;
	    han.printGraph(true);
	    cout << endl;

	return 1;
}

