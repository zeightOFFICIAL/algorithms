/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V, Kuksin A.A
Lab 4,5
Graph algorithms. Algorightms of finding 
minimum spanning tree and shortest route:
- Graph generator (undirected graph)
    - Adjacency matrix
    - Distances matrix
- Prim's algorithm (minimal spanning tree, MST)
- Kruskal's algorithm (MST)
- Dijkstra algorithm (Shortest path on graph, SPG)
- Floyd-Warshall's algorithm (SPG)
- Johnson's algorithm (SPG)
main.cpp
15.03.2022
ver 0.85
*/

#include <iostream>
#include <fstream>
#include <random>
#include <cmath>

#include "graph/graph.h"

#include "minimum_spanning_tree/prim.h"
#include "minimum_spanning_tree/kruskal.h"

#include "shortest_path_on_graph/dijkstra.h"
#include "shortest_path_on_graph/floyd_warshall.h"
#include "shortest_path_on_graph/johnson.h"

using namespace std;

int main() {
cout<<"Start."<<"\n===================================\n";
    Graph Graph1(10,17);
    Graph1.GenerateGraph(9);
    
    //MST_prim(Graph1.GetDistancesMatrix());
    //MST_kruskal(Graph1.ListOfEdges(),Graph1.GetNoVertex());
    
    //SPG_dijkstra(Graph1.GetDistancesMatrix());
    //SPG_floyd(Graph1.GetDistancesMatrix());
    //SPG_johnson(Graph1.GetDistancesMatrix());
cout<<"End."<<"\n===================================\n"; 
}