#include <iostream>
#include <vector>

//delete ................
#include <ctime>
//.......................

#include "floyd_warshall.h"
#include "limits.h"


std::vector<std::vector<int>> SPGFloydTable(std::vector<std::vector<int>> distances_matrix)
{
    int number_of_vertex = distances_matrix.size(), i, j, k;
    std::vector<std::vector<int>> map;
    map.resize(number_of_vertex, std::vector<int>(number_of_vertex, 0));
    //.............
    clock_t t;
    //.............
    
    for (i = 0; i < number_of_vertex; i++)
        for (j = 0; j < number_of_vertex; j++) {
                if (i == j)
                    map[i][j] = 0;
                else if (distances_matrix[i][j] == 0)
                    map[i][j] = INT_MAX;
                else
                    map[i][j] = distances_matrix[i][j];
                }
    //.............
    t = clock();
    //.............
    for (k = 0; k < number_of_vertex; k++)
        for (i = 0; i < number_of_vertex; i++)
            for (j = 0; j < number_of_vertex; j++)  {
                    if (map[i][j]>(map[i][k]+map[k][j])&&
                        (map[k][j]!=INT_MAX && map[i][k]!=INT_MAX))
                        map[i][j]=map[i][k]+map[k][j];
                }
    //.............
    t = clock() - t;
    std::cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<"\n";
    //.............
    return map;
}

void SPGFloydTablePrint(std::vector<std::vector<int>> distances_matrix)
{
    int number_of_vertices = distances_matrix.size();
    std::vector<std::vector<int>> SPG_floyd_table;
    SPG_floyd_table = SPGFloydTable(distances_matrix);
    
    for (int j = 0; j < number_of_vertices; j++) {
        for (int l = 0; l < number_of_vertices; l++)
            std::cout<<SPG_floyd_table[j][l]<<", ";
        std::cout<<"\n";
        }
}