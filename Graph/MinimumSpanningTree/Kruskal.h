// Kruskal.h

#include <algorithm>
#include <vector>

namespace mst {
  typedef std::vector<std::vector<int>> vector;

  class DSU {
    int *parent;
    int *rank;
  
  public:
    DSU(int n);
    void Unite(int x, int y);
    int Set(int i);
  };
  
  vector MSTKruskal(vector EdgeList, int NoVertex);
  
  DSU::DSU(int size) {
    parent = new int[size];
    rank = new int[size];
  
    for (int each = 0; each < size; each++) {
      parent[each] = -1;
      rank[each] = 1;
    }
  }
  
  int DSU::Set(int element) {
    if (parent[element] == -1)
      return element;
    return parent[element] = Set(parent[element]);
  }
  
  void DSU::Unite(int x, int y) {
    int FirstSet = Set(x);
    int SecondSet = Set(y);
  
    if (FirstSet != SecondSet) {
      if (rank[FirstSet] < rank[SecondSet]) {
        parent[FirstSet] = SecondSet;
        rank[SecondSet] += rank[FirstSet];
      } else {
        parent[SecondSet] = FirstSet;
        rank[FirstSet] += rank[SecondSet];
      }
    }
  }
  
  vector MSTKruskal(vector edgesList, int vertices) {
    sort(edgesList.begin(), edgesList.end());
    DSU setunion(vertices);
    vector table;
  
    for (auto edge : edgesList) {
      int weight = edge[0];
      int src = edge[1];
      int dst = edge[2];
      if (setunion.Set(src) != setunion.Set(dst)) {
        setunion.Unite(src, dst);
        table.push_back({src, dst, weight});
      }
    }
  
    return table;
  }
} // namespace mst