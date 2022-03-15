#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>

#include "../tools/SortingAlgorithms.h"
#include "reverse_delete.h"

using namespace std;

int MST_redelete(vector<vector<int>> DistancesMatrix, int NoEdges)
{
    int NoVertex = DistancesMatrix.size();
    int Edges[NoEdges], Map[NoEdges][3];
    int k = 0, MinCost = 0, Count = 0, CountMap = 0;
    vector<int> NoConnections;
    NoConnections.resize(NoVertex,0);

    for (int i = 0; i < NoVertex; i++)
            for (int j = i; j < NoVertex; j++)  {
                    if (DistancesMatrix[i][j]==0)
                        continue;
                    Edges[k]=DistancesMatrix[i][j];
                    k++;
                }
    for (int i = 0; i < NoVertex; i++)
            for (int j = 0; j < NoVertex; j++)
                    if ((DistancesMatrix[i][j]!=0) && (i!=j))
                        NoConnections[i]++;
    
    SortArray_HeapSort(Edges,NoEdges);    
    int ThisWeight = 0;   
    int j;
    
        for (int i = NoEdges; i > 0; i--)  {
            ThisWeight = Edges[i-1];
            //cout<<ThisWeight<<" --- \n";
            for (k = 0; k < NoVertex; k++)  {
                for (j = 0; j < NoVertex; j++)  {
                    //cout<<k<<" "<<j<<" PREPREPRE\n";
                    if (DistancesMatrix[k][j]==ThisWeight)  {     
                            //cout<<k<<" "<<j<<" =-="<<DistancesMatrix[k][j]<<"\n";
                            DistancesMatrix[k][j]=0;
                            DistancesMatrix[j][k]=0;
                            
                            NoConnections[k]--;
                            NoConnections[j]--;
                            if (NoConnections[k]==0) {
                                cout<<k<<" "<<j<<"\n";
                                MinCost = MinCost + ThisWeight;
                                DistancesMatrix[k][j]=ThisWeight;
                                DistancesMatrix[j][k]=ThisWeight;
                                }               
                            //if (NoConnections[j]==0) {
                                //cout<<k<<" "<<j<<"\n";
                                //MinCost = MinCost + ThisWeight;
                                //DistancesMatrix[k][j]=ThisWeight;
                                //DistancesMatrix[j][k]=ThisWeight;
                                //}
                        }
                    }
                }
            //for (int l = 0; l < NoVertex; l++)
            //      cout<<NoConnections[l]<<"\n";
            //cout<<"-------\n";
        }

            
    //for (int x = 0; x < NoEdges; x++)
        //cout<<Map[x][0]<<" - "<<Map[x][1]<<" "<<Map[x][2]<<"\n";
    cout<<"Total cost is: "<<MinCost<<endl;

    return MinCost;
}

