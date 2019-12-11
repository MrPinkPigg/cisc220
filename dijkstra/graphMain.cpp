/*
 * graphMain.cpp
 *
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include "graph.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    srand (time(NULL));
    string names[12] =
    {"Albany","Buffalo","Chicago","Detroit","Encino","Fargo","Gotham","Houston","Indianapolis","Jackson","Kenosha","Lewiston"};

    int size = 4;
    graph g1(size, 3, names);
    cout<<endl<<"**********************************************************************"<<endl;

    size = 7;
    graph g2(size,6,names);
    cout<<endl<<"**********************************************************************"<<endl;

    size = 12;
    graph g3(size,11,names);
}



