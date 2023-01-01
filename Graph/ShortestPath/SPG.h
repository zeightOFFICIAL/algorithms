// SPG.h

#pragma once

#include "../Graph.h"

#include "Dijkstra.h"
#include "FloydWarshall.h"
#include "Johnson.h"

class SPG : public Graph {
  typedef std::vector<std::vector<int>> vector;

private:
  vector SPGTable;

public:
  explicit SPG();
  explicit SPG(Graph &grph);
  virtual ~SPG();

  vector SpgDijstra();
  vector SpgFloyd();
  vector SpgJohnson();

  void SpgPrintTable();
  vector GetTable();
};

SPG::SPG() {}

SPG::SPG(Graph &grph) {
  DistancesMatrix = grph.GetDistancesMatrix();
  AdjacencyMatrix = grph.GetAdjacencyMatrix();
}

SPG::~SPG() {}

std::vector<std::vector<int>> SPG::SpgDijstra() {
  if (DistancesMatrix.size() <= 0)
    std::cout << "the matrix is undefined" << "\n";
  else {
    SPGTable = SPGDijkstraTable(DistancesMatrix);
    return SPGTable;
  }
  return {{0}};
}

std::vector<std::vector<int>> SPG::SpgFloyd() {
  if (DistancesMatrix.size() <= 0)
    std::cout << "The matrix is undefined" << "\n";
  else {
    SPGTable = SPGFloydTable(DistancesMatrix);
    return SPGTable;
  }
  return {{0}};
}

std::vector<std::vector<int>> SPG::SpgJohnson() {
  if (DistancesMatrix.size() <= 0)
    std::cout << "The matrix is undefined" << "\n";
  else {
    SPGTable = SPGJohnsonTable(DistancesMatrix);
    return SPGTable;
  }
  return {{0}};
}

void SPG::SpgPrintTable() {
  int vertices = DistancesMatrix.size();
  std::cout << "Shortest path matrix:\n";
  for (int j = 0; j < vertices; j++) {
    std::cout << "\t";
    for (int l = 0; l < vertices; l++) {
      std::cout << std::setw(3) << std::left << SPGTable[j][l];
    }
    std::cout << "\n";
  }
}