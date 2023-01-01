//reverse_delete.h 1127
#pragma once

#include <vector>
#include <algorithm>

bool GraphConnected(std::vector<std::vector<int>> edges_list, int number_of_vertices);
void GraphTraverse(int start_vertex, std::vector<bool> &visited, std::vector<std::vector<int>> graph);
std::vector<std::vector<int>> MSTReverseDelete(std::vector<std::vector<int>> edges_list, int number_of_vertices);

void GraphTraverse(int start_vertex, std::vector<bool> &visited, std::vector<std::vector<int>> graph)
{
    visited[start_vertex] = true;
    for (int through = 0; through < visited.size(); through++) {
        if (graph[start_vertex][through]) {
            if (!visited[through])
                GraphTraverse(through, visited, graph);
        }
    }
}

bool GraphConnected(std::vector<std::vector<int>> edges_list, int number_of_vertices)
{  
    std::vector<std::vector<int>> graph;
    std::vector<bool> visited;
    graph.clear();
    graph.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    visited.resize(number_of_vertices, false);
    for (int each_edge = 0; each_edge < edges_list.size(); each_edge++) {
        graph[edges_list[each_edge][1]][edges_list[each_edge][2]] = static_cast<bool>(edges_list[each_edge][0]);
        graph[edges_list[each_edge][2]][edges_list[each_edge][1]] = static_cast<bool>(edges_list[each_edge][0]);
    }
    for (int this_vertex = 0; this_vertex < number_of_vertices; this_vertex++) {
        for (int next_vertex = 0; next_vertex < number_of_vertices; next_vertex++)
            visited[next_vertex] = false;
        GraphTraverse(this_vertex, visited, graph);
        for (int next_vertex = 0; next_vertex < number_of_vertices; next_vertex++)
            if (!visited[next_vertex])
                return false;
    }
    return true;
}

std::vector<std::vector<int>> MSTReverseDelete(std::vector<std::vector<int>> edges_list, int number_of_vertices)
{
    std::vector<std::vector<int>> mst_redelete_table, edges = edges_list, temp_edges_list;
    std::sort(edges.begin(), edges.end());
    for (int each_vertex = edges.size()-1; each_vertex >= 0; each_vertex--) {
        temp_edges_list = edges;
        edges.pop_back();
        if (!GraphConnected(edges, number_of_vertices)) {
            edges = temp_edges_list;
            mst_redelete_table.push_back({ edges[each_vertex][1], edges[each_vertex][2], edges[each_vertex][0] });
            }
    }
    return mst_redelete_table;
}