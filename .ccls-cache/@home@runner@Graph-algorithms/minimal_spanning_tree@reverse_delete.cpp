#include <iostream>
#include <ctime>
#include "../tools/SortingAlgorithms.h"

#include "reverse_delete.h"
using namespace std;

int MST_redelete(int** Array, int NoVertex)
{
    int MinCost,i,j;
    int Edges[NoVertex*NoVertex];
    int Map[NoVertex][2];
    int NoEdges = 0;
    
    for (i = 0; i < NoVertex; i++)
            for (j = i; j < NoVertex; j++)  {
                    if (Array[i][j]==0)
                        continue;
                    Edges[NoEdges]=Array[i][j];
                    NoEdges++;
                }

    SortArray_HeapSort(Edges,NoEdges);
    int CountMap = 0;

    for (i = NoEdges; i >= 0; i--)
        {
            for (int j = 0; j < NoVertex; j++)
                for (int k = j; k < NoVertex; k++)
                    {
                        if (Array[j][k]==Edges[i])
                        {
                            Array[j][k]=0;
                            Array[k][j]=0;
                            Edges[i]=0;
                        }
                    }
        }
    
    
    cout<<"=========================================================\n2.2 Reverse-delete MST\nEdge: \tWeight:\n";  
    for (int i = 0; i< CountMap; i++) {
		//cout<<Map[i][0]<<" - "<<Map[i][1]<<" \t"<<Edges[i]<<" \n";  
		MinCost=MinCost+Edges[i];
    }
    //cout<<"Total cost is: "<<MinCost<<endl;
    
    return MinCost;
}

         