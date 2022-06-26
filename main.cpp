/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 4, 5
Graph algorithms. 
Algorithms of finding minimum spanning tree and shortest route:
- Prim's algorithm (minimal spanning tree, MST)
- Kruskal's algorithm (MST)
- Dijkstra algorithm (Shortest path on graph, SPG)
- Floyd-Warshall's algorithm (SPG)
- Johnson's algorithm (SPG)
originally build on
Clang++ 12 (12.0.1)
compatible with
MSVC 142 (14.29)
main.cpp
25.06.2022
ver 1.107
*/

#include <iostream>

#include "graph/graph.h"

//#include "minimum_spanning_tree/prim.h"
//#include "minimum_spanning_tree/kruskal.h"

// "shortest_path_on_graph/dijkstra.h"
//#include "shortest_path_on_graph/floyd_warshall.h"
//#include "shortest_path_on_graph/johnson.h"

int main() 
{
    Graph Graph1;
    Graph1.GenerateGraph(10,25,20);
    Graph1.PrintAdjacencyMatrix();
    //Graph1.LoadGraph("test.txt");
    //Graph1.PrintDistancesMatrix();
    //Graph1.SaveGraph("test.txt");    
    //Graph1.PrintEdgesList();
    
    //MST_prim(Graph1.GetDistancesMatrix());
    //MST_kruskal(Graph1.GetEdgesList(),Graph1.GetNumberVertices());

    //SPGDijkstraTable(Graph1.GetDistancesMatrix());
    //SPGFloydTable(Graph1.GetDistancesMatrix());
    //SPGJohnsonTable(Graph1.GetDistancesMatrix());
    return 0;
}