#include <iostream>
#include "dijkstra_algorithm.h"
#include "limits.h"
using namespace std;

int SPG_minkey(int Keys[], bool Visited[], int NoVertex)  
{ 
    int Min = INT_MAX, MinIndex;
    for (int v = 0; v < NoVertex; v++)
        if (Visited[v] == false && Keys[v] < Min) { 
            Min = Keys[v];
			MinIndex = v; }
    return MinIndex;  
}  

void SPG_dijkstra(int** Array, int NoVertex)
{
    int Map[NoVertex];
    bool MapSpt[NoVertex];
    clock_t t;
    t = clock();

    for (int i = 0; i < NoVertex; i++)
        Map[i] = INT_MAX, MapSpt[i] = false;
    Map[0]=0;

    for (int count = 0; count < NoVertex - 1; count++)
        {
            int u = SPG_minkey(Map,MapSpt,NoVertex);
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
}