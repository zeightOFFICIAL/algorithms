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
- Johnson's algorithm (SPG)
main.cpp
14.03.2022
ver 0.55
*/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>

#include "graph/graph.h"
#include "tools/SortingAlgorithms.h"

#include "minimum_spanning_tree/prim.h"
#include "minimum_spanning_tree/reverse_delete.h"

#include "shortest_path_on_graph/dijkstra.h"
#include "shortest_path_on_graph/floyd_warshall.h"
#include "shortest_path_on_graph/johnson.h"

using namespace std;

int main() {

    int **Array;
    Array = new int *[500];
    for(int i = 0; i <500; i++)
        Array[i] = new int[500];
    int NoVertex = 0;
    int MinCost = 0;
    
cout<<"Start."<<"\n===================================\n";
    Graph Graph1(5,7);
    Graph1.GenerateGraph(9);
    
    //MST_prim(Graph1.GetDistancesMatrix());
    //MST_redelete(Graph1.GetDistancesMatrix(),Graph1.GetNoEdges());
    //MST_(Array,NoVertex);
    
    //SPG_dijkstra(Graph1.GetDistancesMatrix());
    //SPG_floyd(Graph1.GetDistancesMatrix());
    //SPG_johnson(Graph1.GetDistancesMatrix());
cout<<"End."<<"\n===================================\n"; 
    delete[] Array;
}