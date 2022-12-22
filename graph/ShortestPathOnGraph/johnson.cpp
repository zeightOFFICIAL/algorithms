#include <vector>

#include "johnson.h"
#define INF 999999

std::vector<std::vector<int>> SPGJohnsonTable(std::vector<std::vector<int>> distances_matrix)
{
    int number_of_vertex = distances_matrix.size();
    std::vector<std::vector<int>> spg_johnson_table;
    spg_johnson_table.resize(number_of_vertex, std::vector<int>(number_of_vertex, 0));

    for (int src_vertex = 0; src_vertex < number_of_vertex; src_vertex++)
        for (int dst_vertex = 0; dst_vertex < number_of_vertex; dst_vertex++) {
            if (src_vertex == dst_vertex)
                spg_johnson_table[src_vertex][dst_vertex] = 0;
            else if (distances_matrix[src_vertex][dst_vertex] == 0)
                spg_johnson_table[src_vertex][dst_vertex] = INF;
            else
                spg_johnson_table[src_vertex][dst_vertex] = distances_matrix[src_vertex][dst_vertex];
            }

    for (int k = 0; k < number_of_vertex; k++)
      for (int i = 0; i < number_of_vertex; i++)
         for (int j = 0; j < number_of_vertex; j++)
            spg_johnson_table[i][j] = std::min(spg_johnson_table[i][j], spg_johnson_table[i][k] + spg_johnson_table[k][j]);

    return spg_johnson_table;
}