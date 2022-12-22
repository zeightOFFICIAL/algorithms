#include <vector>
#include <algorithm>

#include "kruskal.h"

DSU::DSU(int total_size)  {
        parent = new int[total_size];
        rank = new int[total_size];
        for (int this_element = 0; this_element < total_size; this_element++) {
            parent[this_element] = -1;
            rank[this_element] = 1;
        }
    }
int DSU::find_set(int this_element)  {
        if (parent[this_element] == -1)
            return this_element;
        return parent[this_element] = find_set(parent[this_element]);
    }
void DSU::unite_sets(int x, int y)  {
        int frst_set = find_set(x);
        int scnd_set = find_set(y);
        if (frst_set != scnd_set) {
            if (rank[frst_set] < rank[scnd_set]) {
                parent[frst_set] = scnd_set;
                rank[scnd_set] += rank[frst_set];
            }
            else {
                parent[scnd_set] = frst_set;
                rank[frst_set] += rank[scnd_set];
            }
        }
    }

std::vector<std::vector<int>> MSTKruskal(std::vector<std::vector<int>> edges_list, int number_of_vertex)
{
    sort(edges_list.begin(),edges_list.end());
    DSU setunion(number_of_vertex);
    std::vector<std::vector<int>> mst_kruskal_table;    
    for (auto edge : edges_list) {
            int weight = edge[0];
            int src = edge[1];
            int dst = edge[2];
            if (setunion.find_set(src) != setunion.find_set(dst)) {
                setunion.unite_sets(src, dst);
                mst_kruskal_table.push_back({ src, dst, weight });
            }
    }
    return mst_kruskal_table;
}
    