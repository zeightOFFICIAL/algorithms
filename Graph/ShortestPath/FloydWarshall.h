// FloydWarshall.h

#include "limits.h"
#include <vector>

namespace spg {
  typedef std::vector<std::vector<int>> vector;
  vector FloydTable(vector DistanceMatrix);
  
  vector FloydTable(vector DistancesMatrix) {
    int vertices = DistancesMatrix.size(), srcVertex, dstVertex, k;
    vector SpgTable;
    SpgTable.resize(vertices, std::vector<int>(vertices, 0));
  
    for (srcVertex = 0; srcVertex < vertices; srcVertex++)
      for (dstVertex = 0; dstVertex < vertices; dstVertex++) {
        if (srcVertex == dstVertex)
          SpgTable[srcVertex][dstVertex] = 0;
        else if (DistancesMatrix[srcVertex][dstVertex] == 0)
          SpgTable[srcVertex][dstVertex] = INT_MAX;
        else
          SpgTable[srcVertex][dstVertex] = DistancesMatrix[srcVertex][dstVertex];
      }
    for (k = 0; k < vertices; k++)
      for (srcVertex = 0; srcVertex < vertices; srcVertex++)
        for (dstVertex = 0; dstVertex < vertices; dstVertex++) {
          if (SpgTable[srcVertex][dstVertex] >
                  (SpgTable[srcVertex][k] + SpgTable[k][dstVertex]) &&
              (SpgTable[k][dstVertex] != INT_MAX &&
               SpgTable[srcVertex][k] != INT_MAX))
            SpgTable[srcVertex][dstVertex] =
                SpgTable[srcVertex][k] + SpgTable[k][dstVertex];
        }
  
    return SpgTable;
  }
} // namespace spg