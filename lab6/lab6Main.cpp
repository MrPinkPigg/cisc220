/*
 *
 * lab6Main.cpp
 *
 * Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include "makeSeuss.hpp"
#include "hashMap.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>


int main(){
	srand( time(NULL) );
    makeSeuss("DrSeuss.txt", "h1c1.txt", true, true);
    makeSeuss("DrSeuss.txt", "h1c2.txt", true, false);
    makeSeuss("DrSeuss.txt", "h2c1.txt", false, true);
    makeSeuss("DrSeuss.txt", "h2c2.txt", false, false);
    return 0;
}


