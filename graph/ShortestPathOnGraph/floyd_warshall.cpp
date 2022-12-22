#include <vector>

#include "floyd_warshall.h"
#include "limits.h"

std::vector<std::vector<int>> SPGFloydTable(std::vector<std::vector<int>> distances_matrix)
{
    int number_of_vertex = distances_matrix.size(), source_vertex, dstnt_vertex, k;
    std::vector<std::vector<int>> spg_floyd_table;
    spg_floyd_table.resize(number_of_vertex, std::vector<int>(number_of_vertex, 0));
    
    for (source_vertex = 0; source_vertex < number_of_vertex; source_vertex++)
        for (dstnt_vertex = 0; dstnt_vertex < number_of_vertex; dstnt_vertex++) {
                if (source_vertex == dstnt_vertex)
                    spg_floyd_table[source_vertex][dstnt_vertex] = 0;
                else if (distances_matrix[source_vertex][dstnt_vertex] == 0)
                    spg_floyd_table[source_vertex][dstnt_vertex] = INT_MAX;
                else
                    spg_floyd_table[source_vertex][dstnt_vertex] = distances_matrix[source_vertex][dstnt_vertex];
                }
    for (k = 0; k < number_of_vertex; k++)
        for (source_vertex = 0; source_vertex < number_of_vertex; source_vertex++)
            for (dstnt_vertex = 0; dstnt_vertex < number_of_vertex; dstnt_vertex++)  {
                    if (spg_floyd_table[source_vertex][dstnt_vertex]>(spg_floyd_table[source_vertex][k]+spg_floyd_table[k][dstnt_vertex])&&
                       (spg_floyd_table[k][dstnt_vertex]!=INT_MAX && spg_floyd_table[source_vertex][k]!=INT_MAX))
                        spg_floyd_table[source_vertex][dstnt_vertex]=spg_floyd_table[source_vertex][k]+spg_floyd_table[k][dstnt_vertex];
                }

    return spg_floyd_table;
}