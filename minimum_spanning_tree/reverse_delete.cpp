#include <vector>
#include <algorithm>
#include <iostream>

bool GraphConnected(std::vector<std::vector<int>> edges_list)
{
    bool left_connected = false, right_conencted = false;
    for (int i = 0; i < edges_list.size(); i++)
        std::cout << edges_list[i][0] << " " << edges_list[i][1] << " " << edges_list[i][2] << "\n";
    for (int edge_index = 0; edge_index < edges_list.size(); edge_index++)  {
        left_connected = false, right_conencted = false;
        for (int next_index = 0; next_index < edges_list.size(); next_index++)  {
            int active_nodes[2] = {edges_list[edge_index][1], edges_list[edge_index][2]}; 
            if (edge_index == next_index)
                continue;
            else {
                if (active_nodes[0] == edges_list[next_index][1] or edges_list[next_index][2])
                    left_connected = true;
                if (active_nodes[1] == edges_list[next_index][1] or edges_list[next_index][2])
                    right_conencted = true;
            }
        }
        if (!left_connected or !right_conencted)
            return false;
    }
    return left_connected;
}

std::vector<std::vector<int>> MSTReverseDelete(std::vector<std::vector<int>> edges_list)
{
    std::vector<std::vector<int>> mst_redelete_table, edges = edges_list, temp_edges_list;
    std::sort(edges.begin(), edges.end());
    
    for (int each_vertex = edges.size()-1; each_vertex >= 0; each_vertex--) {
        temp_edges_list = edges;
        edges.pop_back();
        std::cout << each_vertex << "\n";
        if (!GraphConnected(edges)) {
            std::cout << "hit ya" << "\n";
            edges = temp_edges_list;
            mst_redelete_table.push_back({ edges[each_vertex][1], edges[each_vertex][2], edges[each_vertex][0] });
            continue;
        }
    }
    return mst_redelete_table;
}