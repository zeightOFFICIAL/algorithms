#include <iostream>
#include <ctime>

#include "floyd_warshall.h"
#include "limits.h"

#define INF 999999
using namespace std;

void SPG_floyd(int** Array, int NoVertex) 
{
    int Map[NoVertex][NoVertex], i, j, k;
    clock_t t;
    
    for (i = 0; i < NoVertex; i++)
        for (j = 0; j < NoVertex; j++) {
                if (i == j)
                    Map[i][j] = 0;
                else if (Array[i][j] == 0)
                    Map[i][j] = INF;
                else
                    Map[i][j] = Array[i][j];
                }

    t = clock();
    for (k = 0; k < NoVertex; k++)
        for (i = 0; i < NoVertex; i++)
            for (j = 0; j < NoVertex; j++)
                {
                    if (Map[i][j]>(Map[i][k]+Map[k][j])&&
                        (Map[k][j]!=INF && Map[i][k]!=INF))
                        Map[i][j]=Map[i][k]+Map[k][j];
                }
    
    t = clock() - t;
    cout<<"=========================================================\n3.2 Floyd-Warshall's SPG\n";  
    for (i = 0; i < NoVertex; i++) 
        {
            for (k = 0; k < NoVertex; k++)
                cout<<Map[i][k]<<", ";
            cout<<endl; 
        }
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}
