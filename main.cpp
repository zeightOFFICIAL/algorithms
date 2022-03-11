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
- Prim's algorithm (minimal spanning tree, MST)
- Reverse delete algorithm (minimal spanning tree, MST)
-

- Dijkstra algorithm (Shortest path on graph)
- Floyd-Warshall's algorithm (SPG)
-
main.cpp
10.03.2022
ver 0.4
*/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>

#include "graph_generate/generategraph.h"

#include "spanning_tree/prim_algorithm.h"
//#include "spanning_tree/reverse_delete_algorithm.h"

#include "shortest_route/dijkstra_algorithm.h"
#include "shortest_route/floyd_warshall.h"

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
    //MinCost=MST_prim(Array,NoVertex);
    //SPG_dijkstra(Array, NoVertex);
    SPG_floyd(Array, NoVertex);
cout<<"End."<<"\n=========================================================\n"; 
    delete[] Array;
}