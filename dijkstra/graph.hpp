/*
 * graph.hpp
 *
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */
#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <iostream>
#include <stdlib.h>
using namespace std;
class graph {
    int **adjMatrix;
    int numOfVerts;
    int start;
    string *dataArr;
    //BinHeap priorityQueue();
    bool *visited;
    int *distances;
    int *prev;
public:
    graph(int n, int first, string vertexnames[]);
    void dijkstra();
    void setDistances(int lv);
    int minDistance();
    void printAdjMat();
    void printInfoSoFar();
    void printPath(int end);
    void genGraph();
};
#endif /* GRAPH_HPP_ */
