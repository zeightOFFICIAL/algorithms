#include <vector>
#include <algorithm>
#include <iostream>

bool GraphConnected(std::vector<std::vector<int>> edges_list)
{
    for (int edge_index = 0; edge_index < edges_list.size(); edge_index++)  {
        int side_vertex[2] = {edges_list[edge_index][1], edges_list[edge_index][2]};
        for (int next_index = 0; next_index < edges_list.size(); next_index++) {
            if (next_index == edge_index)
                continue;
            else {
                if ((side_vertex[0] == edges_list[next_index][1]) 
                    or (side_vertex[1] == edges_list[next_index][1]) 
                    or (side_vertex[0] == edges_list[next_index][2])
                    or (side_vertex[1] == edges_list[next_index][2]))
                    break;
                else if (next_index == edges_list.size()-1)
                    return false;
            }
        }
    }
    return true;
}

std::vector<std::vector<int>> MSTReverseDelete(std::vector<std::vector<int>> edges_list)
{
    std::vector<std::vector<int>> mst_redelete_table, edges = edges_list;
    std::vector<int> temp_edge;
    std::sort(edges.begin(), edges.end());
    std::reverse(edges.begin(), edges.end());
    std::cout << GraphConnected(edges);

    return mst_redelete_table;
}