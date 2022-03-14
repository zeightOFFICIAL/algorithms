#include <iostream>
#include <vector>
#include <ctime>

#include "dijkstra.h"
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

void SPG_dijkstra(vector<vector<int>> DistancesMatrix)
{
    int NoVertex = DistancesMatrix.size();
    int Map[NoVertex], CombinedMap[NoVertex][NoVertex];
    bool MapSpt[NoVertex];
    clock_t t;
    t = clock();

    for (int EachVertex = 0; EachVertex < NoVertex; EachVertex++) {
        for (int i = 0; i < NoVertex; i++)
            Map[i] = INT_MAX, MapSpt[i] = false;
        Map[EachVertex]=0;

        for (int EachVisit = 0; EachVisit < NoVertex - 1; EachVisit++) {
                int u = SPG_minkey(Map,MapSpt,NoVertex);
                MapSpt[u] = true;
                for (int v = 0; v < NoVertex; v++)
                        if (!MapSpt[v]&&DistancesMatrix[u][v]&&Map[u]!=INT_MAX&&Map[u]+DistancesMatrix[u][v]<Map[v])
                            Map[v]=Map[u]+DistancesMatrix[u][v];
                }  
        
        for (int j = 0; j < NoVertex; j++)
            CombinedMap[j][EachVertex]=Map[j];
        }
    
    t = clock() - t;
    cout<<"3.1 Dijkstra's SPG\n"; 
    for (int j = 0; j < NoVertex; j++) {
        for (int l = 0; l < NoVertex; l++)
             cout<<CombinedMap[j][l]<<", ";
        cout<<endl; }
     cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}