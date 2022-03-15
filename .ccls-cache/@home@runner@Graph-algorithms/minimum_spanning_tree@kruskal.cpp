#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>

#include "../tools/SortingAlgorithms.h"
#include "kruskal.h"

using namespace std;

DSU::DSU(int n)  {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
int DSU::find(int i)  {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }
void DSU::unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

int MST_kruskal(vector<vector<int>> DistancesMatrix, int NoEdges)
{
    int NoVertex = DistancesMatrix.size();
    int Edges[NoEdges], Map[NoEdges][3];
    int k = 0, MinCost = 0, Count = 0, CountMap = 0;

    for (int i = 0; i < NoVertex; i++)
            for (int j = i; j < NoVertex; j++)  {
                    if (DistancesMatrix[i][j]==0)
                        continue;
                    Edges[k]=DistancesMatrix[i][j];
                    k++;
                }
    
    SortArray_HeapSort(Edges,NoEdges);    
    int ThisWeight = 0;   
    int j;

    DSU s(NoVe)
}
    