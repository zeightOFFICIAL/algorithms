#include <iostream>
#include <vector>
#include <ctime>

#include "floyd_warshall.h"
#include "limits.h"

using namespace std;

void SPG_floyd(vector<vector<int>> DistancesMatrix) 
{
    int NoVertex = DistancesMatrix.size();
    int Map[NoVertex][NoVertex], i, j, k;
    clock_t t;
    
    for (i = 0; i < NoVertex; i++)
        for (j = 0; j < NoVertex; j++) {
                if (i == j)
                    Map[i][j] = 0;
                else if (DistancesMatrix[i][j] == 0)
                    Map[i][j] = INT_MAX;
                else
                    Map[i][j] = DistancesMatrix[i][j];
                }
    t = clock();
    for (k = 0; k < NoVertex; k++)
        for (i = 0; i < NoVertex; i++)
            for (j = 0; j < NoVertex; j++)  {
                    if (Map[i][j]>(Map[i][k]+Map[k][j])&&
                        (Map[k][j]!=INT_MAX && Map[i][k]!=INT_MAX))
                        Map[i][j]=Map[i][k]+Map[k][j];
                }
    t = clock() - t;
    cout<<"3.2 Floyd-Warshall's SPG\n";  
    for (i = 0; i < NoVertex; i++)  {
            for (k = 0; k < NoVertex; k++)
                cout<<Map[i][k]<<", ";
            cout<<endl; 
        }
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}
