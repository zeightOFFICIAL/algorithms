#include <vector>
#include <algorithm>

#include "kruskal.h"

DSU::DSU(int n)  {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)  {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
int DSU::find(int i)  {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }
void DSU::unite(int x, int y)  {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2])  {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else  {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

std::vector<std::vector<int>> MSTKruskal(std::vector<std::vector<int>> edges_list, int number_of_vertex)
{
    sort(edges_list.begin(),edges_list.end());
    DSU s(number_of_vertex);
    std::vector<std::vector<int>> mst_kruskal_table;
    
    for (auto edge : edges_list)  {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if (s.find(x) != s.find(y))  {
                s.unite(x, y);
                mst_kruskal_table.push_back({ x,y,w });
                }
        }
    return mst_kruskal_table;
}
    