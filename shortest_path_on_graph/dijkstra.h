//dijkstra.h 1115
#pragma once

#include <vector>

std::vector<std::vector<int>> SPGDijkstraTable(std::vector<std::vector<int>> distances_matrix);
int SPGMinkey(int key[], bool visited[], int number_of_vertices);