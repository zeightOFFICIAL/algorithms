#include <iostream>
#include <vector>
#include <ctime>

#include "prim.h"
#include "limits.h"

using namespace std;

int min_Key(int key[], bool visited[], int NoVertex)  
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

int MST_prim(vector<vector<int>> DistancesMatrix)
{
    int NoVertex = DistancesMatrix.size();
    int parent[NoVertex], key[NoVertex];
    bool visited[NoVertex];
    clock_t t;
    t = clock();
    
    for (int i = 0; i< NoVertex; i++) { 
        key[i] = 999; 
        visited[i] = false;
        parent[i]=-1;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int x = 0; x < NoVertex - 1; x++)  {  
        int u = min_Key(key, visited, NoVertex);
        visited[u] = true; 
        for (int v = 0; v < NoVertex; v++)  {
            if (DistancesMatrix[u][v]!=0 && visited[v] == false && DistancesMatrix[u][v] < key[v])  {  
                parent[v] = u;
                key[v] = DistancesMatrix[u][v];  
            }        
        }
    }
    int minCost=0;
    t = clock()-t;
	cout<<"2.1 Prim's MST\nEdge: \tWeight:\n";  
    for (int i = 1; i< NoVertex; i++) {
		cout<<parent[i]<<" - "<<i<<" \t"<<DistancesMatrix[i][parent[i]]<<" \n";  
		minCost+=DistancesMatrix[i][parent[i]];
    }
	cout<<"Total cost is: "<<minCost<<endl;
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return minCost;
}