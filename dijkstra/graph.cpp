/*
 * graph.cpp
 *
 *      Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke
 */

#include "graph.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
graph::graph(int n, int first, string vertexnames[]) {
    numOfVerts = n;
    start = first;
    dataArr = new string[n];
    for (int i = 0; i < n; i++) {
        dataArr[i] = vertexnames[i];
    }
    distances = new int[n];
    adjMatrix = new int*[n];
    visited = new bool[n];
    prev = new int[n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n];
    }
    genGraph();
    for (int i = 0; i < n; i++) {
        distances[i] = 1000000;
        visited[i] = false;
        prev[i] = -1;
    }
    printAdjMat();
    dijkstra();
    printPath(1);
}
void graph::dijkstra(){ // 5 pts
    //Step 1:
    //set the distance to the starting vertex to 0 and set
    //the visited array to true for the start index;
    distances[start] = 0;
    visited[start] = true;

    //Step 2:
    // Initialize the distances to the cost of going to each node from the
    //start index (this is done using the adjacency matrix)
    for(int i = 0; i < numOfVerts; i++){
        distances[i] = adjMatrix[start][i];
        prev[i] = start;
    }

    //Step 3:
    //loop until every vertex has been visited, calling the methods
    //minDistance to find the next unvisited vertex with the minimum
    //distance, and then calling setDistances method for every vertex
    //to update distances for the unvisited vertices. (I called printInfoSoFar()
    //in this loop to see the progress of the algorithm)
    bool allVisited = false;
    while(!allVisited){
        allVisited = true;
        for(int i = 0; i < numOfVerts; i++){
            if(visited[i] == false){
                allVisited = false;
            }
        }

        printInfoSoFar();
        setDistances(minDistance());
    }
}

void graph::setDistances(int latestVert) { //8 pts
    // This method updates the distances array with the costs being
    //updated to either their cost so far, or the cost of
    //traveling through the recently visited vertex + the cost of
    //traveling from that vertex to the new vertex (whichever is the
    //minimum). If the minimum is through the recently visited vertex,
    //then update the previous array so that it holds the latest visited
    //vertex's index number
    for(int i = 0; i < numOfVerts; i++){
        if(adjMatrix[latestVert][i] + distances[latestVert] < distances[i]){
            distances[i] = distances[latestVert] + adjMatrix[latestVert][i];
            if(i != latestVert){
                prev[i] = latestVert;
            }
        }
    }
}
int graph::minDistance( ){ //8 pts
    //This method finds the next unvisited vertex with the minimum
    //distance.
    //Once the minimum is found (along with its index in the distance
    //array), the visited array at that index is set to True and that index is
    //returned from this method.
    int min = 10000;
    int indx = 0;
    for(int i = 0; i < numOfVerts; i++){
        if(!visited[i]){
            if(distances[i] < min){
                min = distances[i];
                indx = i;
            }
        }
    }

    visited[indx] = true;
    return indx;
}
//This method prints out the final path from the starting vertex to the end vertex,
//which is the index passed into this method
void graph::printPath(int end){
    int *temppath = new int[numOfVerts];
    int ct = 0;
    temppath[ct] = end;
    int dist = distances[end];
    int prevnode = prev[end];
    ct++;
    while (prevnode != start) {
        temppath[ct] = prevnode;
        prevnode = prev[prevnode];
        ct++;
    }
    temppath[ct] = start;
    cout << "Shortest Path: " << dist<<endl;
    for (int i = ct; i >= 0; i--) {
        cout << dataArr[temppath[i]] << "("<< temppath[i]<<")->";
    }
    cout << endl;
}
//This method prints out the adjacency matrix with the distances
void graph::printAdjMat() {
    cout <<"********************************************" << endl << "Adjacency Matrix (Graph):"<<endl;
    for (int i = 0; i< numOfVerts;i++) {
        for (int j = 0; j < numOfVerts; j++) {
            cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout <<"********************************************" << endl;
}
//This method prints out the information in the distance array, the previous array, and the visited array
//It is called so you can watch the progress of the construction of the shortest path
void graph::printInfoSoFar() {
    cout <<"\t\t";
    for (int i = 0; i < numOfVerts; i++) {
        cout << "\t"<<i;
     }
    cout << endl;
    cout << "Dist:\t\t";
    for (int i = 0; i < numOfVerts; i++) {
        cout <<distances[i]<< "\t";
    }
    cout << endl;
    cout << "Prev:\t\t";
    for (int i = 0; i < numOfVerts; i++) {
        cout <<prev[i]<< "\t";
    }
    cout << endl;
    cout << "Visited:\t";
    for (int i = 0; i < numOfVerts; i++) {
        cout <<visited[i]<< "\t";
    }
    cout << endl;
    cout << endl;
}
//This method generates the distances for the graph. My way of representing vertices that are
//not connected was to set those distances to 100 (it could just as easily been 1000000, but
//that didn’t look as nice when I printed out the adjacency matrix)
void graph::genGraph() {
    srand(time(NULL));
    for (int i = 0; i < numOfVerts; i++) {
        for (int j = 0; j < numOfVerts; j++) {
            if (i == j) {
                adjMatrix[i][j] = 0;
            }
            else {
                adjMatrix[i][j] = rand() % 9 + 1;
                if (adjMatrix[i][j] == 9) {
                    adjMatrix[i][j] = 100;
                }
            }
        }
    }
}


