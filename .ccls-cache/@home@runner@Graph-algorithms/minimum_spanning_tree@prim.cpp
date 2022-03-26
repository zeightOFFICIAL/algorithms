#include <iostream>
#include <vector>
#include <ctime>

#include "prim.h"
#include "limits.h"

using namespace std;

int MinKey(int key[], bool visited[], int NoVertex)  
{ 
    int min = INT_MAX, min_index;
    for (int v = 0; v < NoVertex; v++) { 
        if (visited[v] == false && key[v] < min) { 
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

int MSTPrim(vector<vector<int>> distances_matrix)
{
    int number_of_vertex = distances_matrix.size();
    int parent[number_of_vertex], key[number_of_vertex];
    bool visited[number_of_vertex];
    clock_t t;
    t = clock();
    
    for (int i = 0; i< number_of_vertex; i++) { 
        key[i] = 999; 
        visited[i] = false;
        parent[i]=-1;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int x = 0; x < number_of_vertex - 1; x++)  {  
        int u = MinKey(key, visited, number_of_vertex);
        visited[u] = true; 
        for (int v = 0; v < number_of_vertex; v++)  {
            if (distances_matrix[u][v]!=0 && visited[v] == false && distances_matrix[u][v] < key[v])  {  
                parent[v] = u;
                key[v] = distances_matrix[u][v];  
            }        
        }
    }
    int minCost=0;
    t = clock()-t;
	cout<<"2.1 Prim's MST\nEdge: \tWeight:\n";  
    for (int i = 1; i< number_of_vertex; i++) {
		cout<<parent[i]<<" - "<<i<<" \t"<<distances_matrix[i][parent[i]]<<" \n";  
		minCost+=distances_matrix[i][parent[i]];
    }
	cout<<"Total cost is: "<<minCost<<endl;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return minCost;
}