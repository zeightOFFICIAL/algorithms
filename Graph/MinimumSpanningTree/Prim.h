// Prim.h

#include "limits.h"
#include <vector>

namespace mst {
  #define INF 999999
  typedef std::vector<std::vector<int>> vector;  
  vector MSTPrim(vector DistancesMatrix);
  int MinKey(int key[], bool visited[], int NoVertex);
  
  int MinKey(int key[], bool visited[], int vertices) {
    int min = INT_MAX, minIndex;
    
    for (int v = 0; v < vertices; v++) {
      if (visited[v] == false && key[v] < min) {
        min = key[v];
        minIndex = v;
      }
    }
    
    return minIndex;
  }
  
  vector MSTPrim(vector DistancesMatrix) {
    int vertices = DistancesMatrix.size();
    int *parent = new int[vertices];
    int *key = new int[vertices];
    bool *visited = new bool[vertices];
    vector table;
    
    for (int each = 0; each < vertices; each++) {
      key[each] = INF;
      visited[each] = false;
      parent[each] = -1;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int source = 0; source < vertices - 1; source++) {
      int u = MinKey(key, visited, vertices);
      visited[u] = true;
      for (int destination = 0; destination < vertices; destination++) {
        if (DistancesMatrix[u][destination] != 0 &&
            visited[destination] == false &&
            DistancesMatrix[u][destination] < key[destination]) {
          parent[destination] = u;
          key[destination] = DistancesMatrix[u][destination];
        }
      }
    }
    for (int i = 1; i < vertices; i++)
      table.push_back({parent[i], i, DistancesMatrix[i][parent[i]]});
    
    return table;
  }
  #undef INF
} // namespace mst