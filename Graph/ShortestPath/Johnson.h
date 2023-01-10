/*
Zeight Algorithms: Implementations of some algorithms in C++
Copyright (C) 2023  Artemii Saganenko
*/

// Johnson.h

#include <vector>

namespace spg {
  #define INF 999999
  typedef std::vector<std::vector<int>> vector;
  /**
  (vector<vector<int>> A) -> (vector<vector<int>> B)
  Finds shortest path matrix B of distances matrix A.
  Uses Johnson algorithm. Returns SP matrix B.
  */
  vector JohnsonTable(vector DistancesMatrix);
  
  vector JohnsonTable(vector DistancesMatrix) {
    int vertices = DistancesMatrix.size();
    vector SpgTable;
    SpgTable.resize(vertices, std::vector<int>(vertices, 0));
  
    for (int srcVertex = 0; srcVertex < vertices; srcVertex++)
      for (int dstVertex = 0; dstVertex < vertices; dstVertex++) {
        if (srcVertex == dstVertex)
          SpgTable[srcVertex][dstVertex] = 0;
        else if (DistancesMatrix[srcVertex][dstVertex] == 0)
          SpgTable[srcVertex][dstVertex] = INF;
        else
          SpgTable[srcVertex][dstVertex] = DistancesMatrix[srcVertex][dstVertex];
      }
  
    for (int k = 0; k < vertices; k++)
      for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
          SpgTable[i][j] =
              std::min(SpgTable[i][j], SpgTable[i][k] + SpgTable[k][j]);
  
    return SpgTable;
  }
  #undef INF
} // namespace spg