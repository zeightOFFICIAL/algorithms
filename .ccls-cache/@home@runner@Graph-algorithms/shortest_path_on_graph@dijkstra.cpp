#include <iostream>
#include <vector>
#include <ctime>

#include "dijkstra.h"
#include "limits.h"

using namespace std;

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

void SPGDijkstra(vector<vector<int>> distances_matrix)
{
    int number_of_vertices = distances_matrix.size();
    int map[number_of_vertices], combined_map[number_of_vertices][number_of_vertices];
    bool map_spt[number_of_vertices];
    clock_t t;
    t = clock();

    for (int each_vertex = 0; each_vertex < number_of_vertices; each_vertex++) {
        for (int i = 0; i < number_of_vertices; i++)
            map[i] = INT_MAX, map_spt[i] = false;
        map[each_vertex]=0;

        for (int each_visit = 0; each_visit < number_of_vertices - 1; each_visit++) {
                int u = SPGMinkey(map,map_spt,number_of_vertices);
                map_spt[u] = true;
                for (int v = 0; v < number_of_vertices; v++)
                        if (!map_spt[v]&&distances_matrix[u][v]&&map[u]!=INT_MAX&&map[u]+distances_matrix[u][v]<map[v])
                            map[v]=map[u]+distances_matrix[u][v];
                }  
        for (int j = 0; j < number_of_vertices; j++)
            combined_map[j][each_vertex]=map[j];
        }
    t = clock() - t;
    cout<<"3.1 Dijkstra's SPG\n"; 
    for (int j = 0; j < number_of_vertices; j++) {
        for (int l = 0; l < number_of_vertices; l++)
             cout<<combined_map[j][l]<<", ";
        cout<<endl; }
     cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}