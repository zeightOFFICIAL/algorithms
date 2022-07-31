/* 
Saint Petersburg State University of Telecommunications (SPBSUT)
IKPI-04
Saganenko A.V
Lab 4, 5
Graph algorithms. 
Algorithms of finding minimum spanning tree (MST):
- Prim's algorithm (minimal spanning tree, MST)
- Kruskal's algorithm (MST)
- Reverse delete algorithm (MST)
Algorithms of finding shortest route on graph (SPG):
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
31.07.2022
ver 1.124
*/

#include "graph/graph.h"
#include "shortest_path_on_graph/spg.h"
#include "minimum_spanning_tree/mst.h"

int main() 
{   
    Mst Graph1;
    Graph1.GenerateGraph();
    Graph1.PrintDistancesMatrix();
    Graph1.MstRedelete();
    Graph1.MstPrintTable();
    Graph1.MstPrim();
    Graph1.MstPrintTable();

    return 0;
}