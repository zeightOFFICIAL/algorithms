#include <iostream>
#include <ctime>
#include "reverse_delete.h"
using namespace std;

int MST_redelete(int** Array, int NoVertex)
{
    int MinCost, NoEdges;
    int i,j;
    int MinEdge[NoVertex];
    
    for (i = 0; i < NoVertex; i++)
        {
            for (j = i; j < NoVertex; j++)
                {
                    MinEdge[i] = Array[i][j];
                    cout<<
                }
        }
    
    return MinCost;
}