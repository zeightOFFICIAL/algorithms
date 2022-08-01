#include <vector>
#include <algorithm>
#include <iostream>

bool GraphConnected(std::vector<std::vector<int>> edges_list, int number_of_vertices)
{
    
}

std::vector<std::vector<int>> MSTReverseDelete(std::vector<std::vector<int>> edges_list, int number_of_vertices)
{
    std::vector<std::vector<int>> mst_redelete_table, edges = edges_list, temp_edges_list;
    std::sort(edges.begin(), edges.end());
    for (int each_vertex = edges.size()-1; each_vertex >= 0; each_vertex--) {
        temp_edges_list = edges;
        edges.pop_back();
        std::cout << each_vertex << "\n";
        if (!GraphConnected(edges, number_of_vertices)) {
            std::cout << "hit ya" << "\n";
            edges = temp_edges_list;
            mst_redelete_table.push_back({ edges[each_vertex][1], edges[each_vertex][2], edges[each_vertex][0] });
            continue;
        }
    }
    return mst_redelete_table;
}