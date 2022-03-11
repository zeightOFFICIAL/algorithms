#include <iostream>
#include <ctime>

#include "johnson.h"
#include "limits.h"

#define INF 999999
using namespace std;

void SPG_johnson(int** Array, int NoVertex)
{
    int Map[NoVertex][NoVertex];
    clock_t t;
    
    for (int i = 0; i < NoVertex; i++)
        for (int j = 0; j < NoVertex; j++) {
            if (i == j)
                Map[i][j] = 0;
            else if (Array[i][j] == 0)
                Map[i][j] = INF;
            else
                Map[i][j] = Array[i][j];
            }

    t = clock();
    for (int k = 0; k < NoVertex; k++)
      for (int i = 0; i < NoVertex; i++)
         for (int j = 0; j < NoVertex; j++)
            Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);

    t = clock() - t;
    cout<<"=========================================================\n3.3 Johnsons's SPG\n";  
    for (int i = 0; i < NoVertex; i++) 
        {
            for (int k = 0; k < NoVertex; k++)
                cout<<Map[i][k]<<", ";
            cout<<endl; 
        }
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}