/*
 * lab3-1.cpp
 *
 *  Sept 19, 2019
 *      Author: Aaron Knestaut and Dylan Kirk
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
 * problem 1
 */
class mathQuiz{
	int testNum;
	int testedOn;
	int testedRight;

public:
	mathQuiz(int x){
		testNum = x;
		testedOn = 0;
		testedRight = 0;
	}

	void test(){
		srand(time(NULL));
		int testVal = rand()%12 + 1;
		int ans;
		cout << "What is " << testNum << " * " << testVal << endl;
		cin >> ans;

		if(ans == (testNum * testVal)){
			testedOn++;
			testedRight++;
			cout << "Yes" << endl;
		}
		else{
			testedOn++;
			cout << "No" << endl;
		}
	}

	void result(){
		cout << "You got " << testedRight << " out of " << testedOn << " correct" << endl;
		}
};


/*
 * main function
 *
 * no parameters
 * returns:
 * 		an int
 *
 * the main function that runs and tests all other problems
 */
int main(){
	//problem 1
	mathQuiz m(4);

	for(int i = 0; i < 10; i++){
		m.test();
	}
	m.result();

	return 1;
}

