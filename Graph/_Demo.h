// Demo.h
// use !ONLY! for testing of the program's work
// for version 1.32

#include "Graph.h"
#include "ShortestPath/SPG.h"
#include "MinimumSpanningTree/MST.h"

void testSPG() {
  Graph graph;
  std::vector<std::vector<int>> vec1, vec2, vec3;
  
  graph.GenerateGraph(6, 6);
  graph.SaveGraph("test.txt");
  
  SPG spgGraph(graph);
  vec1 = spgGraph.SpgDijstra();
  std::cout << "Dijkstra's\n";
  spgGraph.SpgPrintTable();

  vec2 = spgGraph.SpgFloyd();
  std::cout << "Floyd-Warshall's\n";
  spgGraph.SpgPrintTable();

  vec3 = spgGraph.SpgJohnson();
  std::cout << "Johnson's\n";
  spgGraph.SpgPrintTable();

  std::cout << "Are equal: " << ((vec1 == vec2) & (vec3 == vec1) & (vec2 == vec3)) << "\n";
  std::cout << "If equality is compromised, check whether the graph is connected." << "\n";
}

void testMST() {
  Graph graph;
  std::vector<std::vector<int>> vec1, vec2, vec3;

  graph.GenerateGraph(6, 6);
  graph.SaveGraph("test.txt");

  MST mstGraph(graph);
  vec1 = mstGraph.MstPrim();
  std::cout << "Prim's\n";
  mstGraph.MstPrintTable();

  vec2 = mstGraph.MstKruskall();
  std::cout << "Kruskall's\n";
  mstGraph.MstPrintTable();

  std::cout << "MST cost equality indicates (but does not guarantee) the equality of each MST." << "\n";
}