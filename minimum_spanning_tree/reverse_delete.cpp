#include <iostream>
#include <ctime>
#include <vector>

#include "../tools/SortingAlgorithms.h"
#include "reverse_delete.h"

using namespace std;

int MST_redelete(vector<vector<int>> DistancesMatrix, int NoEdges)
{
    int NoVertex = DistancesMatrix.size();
    int Edges[NoEdges], k = 0, MinCost = 0, Map[NoEdges][3];
    int CountMap = 0;

    for (int i = 0; i < NoVertex; i++)
            for (int j = i; j < NoVertex; j++)  {
                    if (DistancesMatrix[i][j]==0)
                        continue;
                    Edges[k]=DistancesMatrix[i][j];
                    k++;
                }
    SortArray_HeapSort(Edges,NoEdges);    
    int Count = 0;
    
    for (int i = NoEdges; i > 0; i--)
        {
            int ThisWeight = Edges[i-1];
            for (int k = 0; k < NoVertex; k++)
                for (int j = k; j < NoVertex; j++) {
                    if (DistancesMatrix[k][j]==ThisWeight && j>=k)
                        {
                            DistancesMatrix[k][j]=0;
                            DistancesMatrix[j][k]=0;
                            Edges[i]=0;
                        }
                    Count=0;
                    for (int l = 0; l < NoVertex; l++)
                        {
                            if (DistancesMatrix[k][l]!=0)
                                
                        }
                    }



                    
                   
            }
                    
                    /*
                    if (DistancesMatrix[k][j]==ThisWeight)
                    {
                        DistancesMatrix[k][j]=0;
                        //DistancesMatrix[j][k]=0;
                        Edges[i]=0;
                        Count=0;
                        
                        for (int l = 0; l < NoVertex; l++)
                            if (DistancesMatrix[k][l]>0)
                                Count++;

                        if (Count==0) {
                            Map[i][0]=k;
                            Map[i][1]=j;
                            Map[i][2]=ThisWeight;
                            MinCost = MinCost + ThisWeight;
                            CountMap++;
                            DistancesMatrix[k][j]=ThisWeight;
                            DistancesMatrix[j][k]=ThisWeight;
                            j++;
                            k++;
                            }

                    }
        }
*/
    cout<<"\n";
    for (int i = 0; i < DistancesMatrix.size(); i++)    {
            cout<<"\t";
            for (int j = 0; j < DistancesMatrix.size(); j++)
                cout<<DistancesMatrix[i][j]<<", ";
            cout<<"\n";
        }
    for (int i = 0; i < CountMap; i++)
        cout<<Map[i][0]<<" - "<<Map[i][1]<<" "<<Map[i][2]<<"\n";
    cout<<"Total cost is: "<<MinCost<<endl;

    
/*
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
		//MinCost=MinCost+Edges[i];
    }
    //cout<<"Total cost is: "<<MinCost<<endl;
    */
    return MinCost;
}
