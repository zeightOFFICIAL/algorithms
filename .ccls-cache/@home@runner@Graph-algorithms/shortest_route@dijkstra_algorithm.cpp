#include <iostream>
#include "dijkstra_algorithm.h"
#include "limits.h"
using namespace std;

int min_Dis(int key[], bool visited[], int NoVertex)  
{ 
    int min = 999, min_index;
    for (int v = 0; v < NoVertex; v++) { 
        if (visited[v] == false && key[v] < min) { 
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

int SPG_dijkstra(int** Array, int NoVertex)
{
    int Map[NoVertex];
    bool MapSpt[NoVertex];

    for (int i = 0; i < NoVertex; i++)
        Map[i] = INT_MAX, MapSpt[i] = false;
    Map[0]=0;

    for (int count = 0; count < NoVertex - 1; count++)
        {
            int u = min_Dis(Map,MapSpt,NoVertex);
            MapSpt[u] = true;
            for (int v = 0; v < NoVertex; v++)
                {
                    if (!MapSpt[v]&&Array[u][v]&&Map[u]!=INT_MAX&&Map[u]+Array[u][v]<Map[v])
                        Map[v]=Map[u]+Array[u][v];
                }
        }

    cout<<"=========================================================\n3.1 Dijkstra's SPG\nVertex: \tDistance:\n";  
        for (int i = 1; i < NoVertex; i++) {
            cout<<i<<"\t"<<Map[i]<<endl;
        }
    
    return 0;
}