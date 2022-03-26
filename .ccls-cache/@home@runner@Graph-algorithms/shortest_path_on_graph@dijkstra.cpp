#include <iostream>
#include <vector>
#include <ctime>

#include "dijkstra.h"
#include "limits.h"

using namespace std;

vector<vector<int>> SPGDijkstraTable(vector<vector<int>> distances_matrix)
{
    int number_of_vertices = distances_matrix.size(), map[number_of_vertices];
    bool map_spt[number_of_vertices];
    vector<vector<int>> SPG_dijkstra_table;
    SPG_dijkstra_table.resize(number_of_vertices,vector<int>(number_of_vertices, 0));

    for (int each_vertex = 0; each_vertex < number_of_vertices; each_vertex++)  {
        for (int i = 0; i < number_of_vertices; i++)
            map[i] = INT_MAX, map_spt[i] = false;
        map[each_vertex]=0;
        for (int each_visit = 0; each_visit < number_of_vertices - 1; each_visit++)  {
                int u = SPGMinkey(map,map_spt,number_of_vertices);
                map_spt[u] = true;
                for (int v = 0; v < number_of_vertices; v++)
                        if (!map_spt[v]&&distances_matrix[u][v]&&map[u]!=INT_MAX&&map[u]+distances_matrix[u][v]<map[v])
                            map[v]=map[u]+distances_matrix[u][v];
                }  
        for (int another_vertex = 0; another_vertex < number_of_vertices; another_vertex++)
            SPG_dijkstra_table[another_vertex][each_vertex]=map[another_vertex];
        }
    return SPG_dijkstra_table;
}

void SPGDijkstraTablePrint(vector<vector<int>> distances_matrix)
{
    int number_of_vertices = distances_matrix.size();
    vector<vector<int>> SPG_dijkstra_table;
    SPG_dijkstra_table = SPGDijkstraTable(distances_matrix);
    
    for (int j = 0; j < number_of_vertices; j++) {
        for (int l = 0; l < number_of_vertices; l++)
             cout<<SPG_dijkstra_table[j][l]<<", ";
        cout<<endl; 
        }
}

int SPGMinkey(int keys[], bool visited[], int number_of_vertices)  
{ 
    int min = INT_MAX, min_index;
    for (int v = 0; v < number_of_vertices; v++)
        if (visited[v] == false && keys[v] < min) { 
            min = keys[v];
			min_index = v; 
        }
    return min_index;  
}  
