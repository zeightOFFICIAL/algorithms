// Johnson.h

#include <vector>
#define INF 999999

std::vector<std::vector<int>> SPGJohnsonTable(std::vector<std::vector<int>> DistancesMatrix);

std::vector<std::vector<int>> SPGJohnsonTable(std::vector<std::vector<int>> DistancesMatrix) {
  int vertices = DistancesMatrix.size();
  std::vector<std::vector<int>> SpgTable;
  SpgTable.resize(vertices, std::vector<int>(vertices, 0));

  for (int srcVertex = 0; srcVertex < vertices; srcVertex++)
    for (int dstVertex = 0; dstVertex < vertices; dstVertex++) {
      if (srcVertex == dstVertex)
        SpgTable[srcVertex][dstVertex] = 0;
      else if (DistancesMatrix[srcVertex][dstVertex] == 0)
        SpgTable[srcVertex][dstVertex] = INF;
      else
        SpgTable[srcVertex][dstVertex] =
            DistancesMatrix[srcVertex][dstVertex];
    }

  for (int k = 0; k < vertices; k++)
    for (int i = 0; i < vertices; i++)
      for (int j = 0; j < vertices; j++)
        SpgTable[i][j] =
            std::min(SpgTable[i][j], SpgTable[i][k] + SpgTable[k][j]);

  return SpgTable;
}