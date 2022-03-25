/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 4, 5
Graph algorithms. Algorightms of finding 
minimum spanning tree and shortest route:
- Graph generator
- Prim's algorithm (minimal spanning tree, MST)
- Kruskal's algorithm (MST)
- Dijkstra algorithm (Shortest path on graph, SPG)
- Floyd-Warshall's algorithm (SPG)
- Johnson's algorithm (SPG)
main.cpp
26.03.2022
ver 0.9
*/

#include <iostream>

#include "graph/graph.h"

#include "minimum_spanning_tree/prim.h"
#include "minimum_spanning_tree/kruskal.h"

#include "shortest_path_on_graph/dijkstra.h"
#include "shortest_path_on_graph/floyd_warshall.h"
#include "shortest_path_on_graph/johnson.h"

using std::cout;

int main() {
cout<<"Start."<<"\n";
    Graph Graph1;
    Graph1.GenerateGraph(10,25,7);
    //Graph1.LoadGraph("test.txt");
    //Graph1.PrintDistancesMatrix();
    //Graph1.SaveGraph("test.txt");    
    //Graph1.PrintEdgesList();
    
    //MST_prim(Graph1.GetDistancesMatrix());
    //MST_kruskal(Graph1.GetEdgesList(),Graph1.GetNumberVertices());
    
    //SPGDijkstra(Graph1.GetDistancesMatrix());
    //SPGFloyd(Graph1.GetDistancesMatrix());
    //SPGJohnson(Graph1.GetDistancesMatrix());
    cout<<"End."<<"\n"; 
}