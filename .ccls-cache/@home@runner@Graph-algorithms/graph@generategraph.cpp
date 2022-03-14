#include <iostream>
#include <fstream>
#include <random>
#include <cmath>

#include "graph.h"

using namespace std;

int GenerateGraph(int** Array,int Power)
/*
    (int** A, int B) -> (int X, int Y) -> (int C)
    Generates graph by creating matrix of adjacency
    and matrix of distances. Both matrixes a truly
    random. Stores matrix in Array** A. And writes
    it in the file. X is a number of Vertices, Y 
    is a number of Edges. B decides the power of 
    each edge. So it is random number from 1..B. 
    Returns the number C which indicates the amount
    of vertices in the matrix C. 
    >>GenerateGraph(Array,9)
    >>Enter the number of vertexes: 5
    >>Enter the number of edges: 7
    <<  1.1 Adjacency matrix:
        0, 1, 0, 1, 1, 
        1, 0, 1, 1, 1, 
        0, 1, 0, 0, 1, 
        1, 1, 0, 0, 0, 
        1, 1, 1, 0, 0, 
        1.2 Distances matrix:
        0, 4, 0, 1, 5, 
        4, 0, 5, 9, 9, 
        0, 5, 0, 0, 1, 
        1, 9, 0, 0, 0, 
        5, 9, 1, 0, 0, 
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
    for (i = 0; i < NoVertex; i++)    {
        for (j = 0; j < NoVertex; j++)
            cout<<DistancesMatrix[i][j]<<", ";
        cout<<endl;
        }
    
    Tool_ClearTxt();
    
    ofstream file;
    file.open("graph/result/adjacency.txt",ios::app);
    for (i = 0; i < NoVertex; i++)
        {
        for (j = 0; j < NoVertex; j++)
            file<<AdjacencyMatrix[i][j]<<", ";
        file<<endl;
        }
    file.close();
    
    file.open("graph/result/distances.txt",ios::app);
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
    file.open("graph/result/adjacency.txt");
    file<<"";
    file.close();
    file.open("graph/result/distances.txt");
    file<<"";
    file.close();
}