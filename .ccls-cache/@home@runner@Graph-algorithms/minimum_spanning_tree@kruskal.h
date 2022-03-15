#include <iostream>
#include <vector>

class DSU
{
    int* parent;
    int* rank;
public:
    DSU(int n);
    void unite(int x, int y);
    int find(int i);
};

int MST_kruskal(std::vector<std::vector<int>> DistancesMatrix, int NoEdges);