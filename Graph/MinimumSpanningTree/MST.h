/*
Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// MST.h
// Helping class for Graph algorithms.
// Might be removed. If so, use algorihtms directly, without Graph and inherited classes.
// for version 1.32

#pragma once

#include "../Graph.h"
#include "Kruskal.h"
#include "Prim.h"
#include <vector>

class MST : public Graph {
typedef std::vector<std::vector<int>> vector;
private:
  vector mstTable;

public:
  explicit MST();
  explicit MST(Graph &grph);
  virtual ~MST();

  vector MstKruskall();
  vector MstPrim();

  void MstPrintTable();
  vector GetVector();
};

MST::MST() {}

MST::MST(Graph &grph) {
  DistancesMatrix = grph.GetDistancesMatrix();
  AdjacencyMatrix = grph.GetAdjacencyMatrix();
}

MST::~MST() {}

std::vector<std::vector<int>> MST::MstKruskall() {
  if (DistancesMatrix.size() <= 0)
    std::cout << "The matrix is undefined" << "\n";
  else {
    mstTable = mst::MSTKruskal(GetEdgesList(), AdjacencyMatrix.size());
    return mstTable;
  }

  return {{0}};
}

std::vector<std::vector<int>> MST::MstPrim() {
  if (DistancesMatrix.size() <= 0)
    std::cout << "The matrix is undefined" << "\n";
  else {
    mstTable = mst::MSTPrim(DistancesMatrix);
    return mstTable;
  }

  return {{0}};
}

void MST::MstPrintTable() {
  int vertices = DistancesMatrix.size();
  int minCost = 0;
  
  std::cout << "Minimum spanning tree matrix:\n";
  for (int l = 0; l < mstTable.size(); l++) {
    std::cout << "\t" << std::setw(2) << std::left << mstTable[l][0] << "- "
              << std::left << std::setw(2) << mstTable[l][1] << std::setw(3)
              << " weight " << mstTable[l][2] << "\n";
    minCost += mstTable[l][2];
  }
  std::cout << "MST cost: " << minCost << "\n";
}