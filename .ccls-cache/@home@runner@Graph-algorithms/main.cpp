/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V, Kuksin A.A
Lab 4,5
Graph algorithms. Algorightms of finding 
minimum spanning tree and shortest route:
- Graph generator (undirected graph)
    - Adjacency matrix (write to file, console)
    - Distances matrix (write to file, console)
- Prim's algorithm (minimal spannign tree, MST)
-
-
-
-
-
main.cpp
10.03.2022
ver 0.25
*/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>

#include "graph_generate/generategraph.h"
#include "spanning_tree/prim_algorithm.h"

using namespace std;

int main() {

    int **Array;
    Array = new int *[500];
    for(int i = 0; i <500; i++)
        Array[i] = new int[500];
    int NoVertex = 0;
    int MinCost = 0;
    
cout<<"Start."<<"\n=========================================================\n";
    NoVertex=GenerateGraph(Array,9);
    MinCost=MST_prim(Array,NoVertex);
cout<<"End."<<"\n=========================================================\n"; 
    delete[] Array;
}