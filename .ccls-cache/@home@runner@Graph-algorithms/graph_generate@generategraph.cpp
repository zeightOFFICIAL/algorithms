#include <iostream>
#include <fstream>
#include <random>
#include <cmath>

#include "generategraph.h"

using namespace std;

int GenerateGraph(int** Array,int Power)
/*
    (int** A, int B) -> (int X, int Y) -> (int C)
    Generates graph by creating matrix of adjacency
    
*/
{
    int NoVertex;
    int NoEdges;
    int AdjacencyMatrix[500][500];

    int StartPoint,EndPoint;
    int i,j,k;
    srand((int)time(0));

    cout<<"-= Generating the undirected graph =-"<<endl;
    cout<<"Enter the number of vertexes: ";
    cin>>NoVertex;    
    cout<<"Enter the number of edges: ";
    cin>>NoEdges;

    for (i = 0; i < NoVertex; i++)
        for (j = 0; j < NoVertex; j++)
            AdjacencyMatrix[i][j]=0;

    k=0;
    NoEdges--;
    while (k<=NoEdges)
        {
            StartPoint = rand()%NoVertex;
            EndPoint = rand()%NoVertex;
            if ((AdjacencyMatrix[StartPoint][EndPoint]!=1) && (StartPoint!=EndPoint))
                {
                    AdjacencyMatrix[StartPoint][EndPoint]=1;
                    AdjacencyMatrix[EndPoint][StartPoint]=1;
                    k++;
                }
            else
                continue;
        }
    cout<<"=========================================================\n1.1 Adjacency matrix:"<<endl;
    for (i = 0; i < NoVertex; i++)
        {
        for (j = 0; j < NoVertex; j++)
            cout<<AdjacencyMatrix[i][j]<<", ";
        cout<<endl;
        }

    
    int DistancesMatrix[500][500];
    int Summer = 5;
    srand((int)time(0));
    
    for (i = 0; i < NoVertex; i++)
        for (j = 0; j < NoVertex; j++)
            {
                Summer=rand()%Power+1;
                DistancesMatrix[i][j]=AdjacencyMatrix[i][j]*Summer;
                DistancesMatrix[j][i]=DistancesMatrix[i][j];
            }
    for(int i=0; i<500; ++i) 
        Array[i]=DistancesMatrix[i];
    cout<<"=========================================================\n1.2 Distances matrix:"<<endl;
    for (i = 0; i < NoVertex; i++)
        {
        for (j = 0; j < NoVertex; j++)
            cout<<DistancesMatrix[i][j]<<", ";
        cout<<endl;
        }
    
    Tool_ClearTxt();
    
    ofstream file;
    file.open("graph_result/adjacency.txt",ios::app);
    for (i = 0; i < NoVertex; i++)
        {
        for (j = 0; j < NoVertex; j++)
            file<<AdjacencyMatrix[i][j]<<", ";
        file<<endl;
        }
    file.close();
    
    file.open("graph_result/distances.txt",ios::app);
    for (i = 0; i < NoVertex; i++)
        {
        for (j = 0; j < NoVertex; j++)
            file<<DistancesMatrix[i][j]<<", ";
        file<<endl;
        }
    file.close();  
    return NoVertex;
}

void Tool_ClearTxt()
{
    ofstream file;
    file.open("graph_result/adjacency.txt");
    file<<"";
    file.close();
    file.open("graph_result/distances.txt");
    file<<"";
    file.close();
}