// Dijkstra.h

#include "limits.h"
#include <vector>

std::vector<std::vector<int>> SPGDijkstraTable(std::vector<std::vector<int>> DistancesMatrix);
int SPGMinkey(int key[], bool visited[], int vertices);

std::vector<std::vector<int>> SPGDijkstraTable(std::vector<std::vector<int>> DistancesMatrix) {
  int vertices = DistancesMatrix.size();
  int *map = new int[vertices];
  bool *mapSpt = new bool[vertices];
  std::vector<std::vector<int>> SpgTable;

  SpgTable.resize(vertices, std::vector<int>(vertices, 0));
  for (int eachVertex = 0; eachVertex < vertices; eachVertex++) {
    for (int i = 0; i < vertices; i++) {
      map[i] = INT_MAX;
      mapSpt[i] = false;
    }
    map[eachVertex] = 0;
    for (int eachVisit = 0; eachVisit < vertices - 1; eachVisit++) {
      int u = SPGMinkey(map, mapSpt, vertices);
      mapSpt[u] = true;
      for (int v = 0; v < vertices; v++)
        if (!mapSpt[v] && DistancesMatrix[u][v] && map[u] != INT_MAX && map[u] + DistancesMatrix[u][v] < map[v])
          map[v] = map[u] + DistancesMatrix[u][v];
    }
    for (int anotherVertex = 0; anotherVertex < vertices; anotherVertex++)
      SpgTable[anotherVertex][eachVertex] = map[anotherVertex];
  }

  delete[] map, mapSpt;
  return SpgTable;
}

int SPGMinkey(int keys[], bool visited[], int vertices) {
  int min = INT_MAX, minIndex;
  
  for (int thisVertex = 0; thisVertex < vertices; thisVertex++)
    if (visited[thisVertex] == false && keys[thisVertex] < min) {
      min = keys[thisVertex];
      minIndex = thisVertex;
    }
  
  return minIndex;
}
