//reverse_delete.h 1126
#pragma once

#include <vector>

bool GraphConnected(std::vector<std::vector<int>> edges_list, int number_of_vertices);
std::vector<std::vector<int>> MSTReverseDelete(std::vector<std::vector<int>> edges_list, int number_of_vertices);