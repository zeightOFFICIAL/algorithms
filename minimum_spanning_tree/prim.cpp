#include <vector>
#include "limits.h"

#include "prim.h"

int MinKey(int key[], bool visited[], int number_of_vertex)  
{ 
    int min = INT_MAX, min_index;
    for (int v = 0; v < number_of_vertex; v++) { 
        if (visited[v] == false && key[v] < min) { 
            min = key[v];
			min_index = v;  
        }
    }
    return min_index;  
}  

std::vector<std::vector<int>> MSTPrim(std::vector<std::vector<int>> distances_matrix)
{
    int number_of_vertex = distances_matrix.size();
    int* parent = new int[number_of_vertex];
    int* key = new int[number_of_vertex];
    bool* visited = new bool[number_of_vertex];
    std::vector<std::vector<int>> mst_prim_table;
    for (int each_vertex = 0; each_vertex< number_of_vertex; each_vertex++) { 
        key[each_vertex] = 999; 
        visited[each_vertex] = false;
        parent[each_vertex]=-1;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int src_vertex = 0; src_vertex < number_of_vertex - 1; src_vertex++)  {  
        int u = MinKey(key, visited, number_of_vertex);
        visited[u] = true; 
        for (int dst_vertex = 0; dst_vertex < number_of_vertex; dst_vertex++)  {
            if (distances_matrix[u][dst_vertex]!=0 && visited[dst_vertex] == false && distances_matrix[u][dst_vertex] < key[dst_vertex])  {  
                parent[dst_vertex] = u;
                key[dst_vertex] = distances_matrix[u][dst_vertex];  
            }        
        }
    }
    for (int i = 1; i< number_of_vertex; i++)
        mst_prim_table.push_back({ parent[i],i, distances_matrix[i][parent[i]] }); 
    return mst_prim_table;
}