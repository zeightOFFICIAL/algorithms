#include <vector>

#include "floyd_warshall.h"
#include "limits.h"


std::vector<std::vector<int>> SPGFloydTable(std::vector<std::vector<int>> distances_matrix)
{
    int number_of_vertex = distances_matrix.size(), source_vertex, dstnt_vertex, k;
    std::vector<std::vector<int>> map;
    map.resize(number_of_vertex, std::vector<int>(number_of_vertex, 0));
    
    for (source_vertex = 0; source_vertex < number_of_vertex; source_vertex++)
        for (dstnt_vertex = 0; dstnt_vertex < number_of_vertex; dstnt_vertex++) {
                if (source_vertex == dstnt_vertex)
                    map[source_vertex][dstnt_vertex] = 0;
                else if (distances_matrix[source_vertex][dstnt_vertex] == 0)
                    map[source_vertex][dstnt_vertex] = INT_MAX;
                else
                    map[source_vertex][dstnt_vertex] = distances_matrix[source_vertex][dstnt_vertex];
                }
    for (k = 0; k < number_of_vertex; k++)
        for (source_vertex = 0; source_vertex < number_of_vertex; source_vertex++)
            for (dstnt_vertex = 0; dstnt_vertex < number_of_vertex; dstnt_vertex++)  {
                    if (map[source_vertex][dstnt_vertex]>(map[source_vertex][k]+map[k][dstnt_vertex])&&
                       (map[k][dstnt_vertex]!=INT_MAX && map[source_vertex][k]!=INT_MAX))
                        map[source_vertex][dstnt_vertex]=map[source_vertex][k]+map[k][dstnt_vertex];
                }
    return map;
}