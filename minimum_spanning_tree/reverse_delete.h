//reverse_delete.h 1127
#pragma once

#include <vector>

bool GraphConnected(std::vector<std::vector<int>> edges_list, int number_of_vertices);
void GraphTraverse(int start_vertex, std::vector<bool> &visited, std::vector<std::vector<int>> graph);
std::vector<std::vector<int>> MSTReverseDelete(std::vector<std::vector<int>> edges_list, int number_of_vertices);