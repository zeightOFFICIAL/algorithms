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
compatible with:
MSVC 142 (14.29)
compatible with:
g++ 7.5.0
main.cpp
25.07.2022
ver 1.115
*/

#include <iostream>

#include "graph/graph.h"
#include "shortest_path_on_graph/spg.h"

int main() 
{
    Spg Graph1;
    Graph1.GenerateGraph();
    Graph1.PrintDistancesMatrix();
    Graph1.SpgDijstra();
    Graph1.SpgPrintTable();
    Graph1.SpgFloyd();
    Graph1.SpgPrintTable();
    
    return 0;
}