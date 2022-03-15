#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <cmath>

#include "graph.h"

using namespace std;

Graph::Graph(int NoVertex, int NoEdges) : NoVertex(NoVertex), NoEdges(NoEdges)
{
    AdjacencyMatrix.resize(NoVertex,vector<int>(NoVertex, 0));
    DistancesMatrix.resize(NoVertex,vector<int>(NoVertex, 0));
}

Graph::~Graph() {}

int Graph::GenerateGraph(int Power)
{
    cout<<"1.0 Generating the undirected graph"<<endl;

    int k = 0;
    int StartPoint, EndPoint;
    srand((int)time(0));

    while (k<=(NoEdges-1))  {
            StartPoint = rand()%(AdjacencyMatrix.size());
            EndPoint = rand()%(AdjacencyMatrix.size());
            if ((AdjacencyMatrix[StartPoint][EndPoint]!=1) && (StartPoint!=EndPoint))  {
                    AdjacencyMatrix[StartPoint][EndPoint]=1;
                    AdjacencyMatrix[EndPoint][StartPoint]=1;
                    k++;
                }
        }
    cout<<"\t1.1 Adjacency matrix:\n";
    for (int i = 0; i < AdjacencyMatrix.size(); i++)  {
            cout<<"\t";
            for (int j = 0; j < AdjacencyMatrix[i].size(); j++)
                    cout<<AdjacencyMatrix[i][j]<<", ";
            cout << "\n";
        }
    int Summer = 1;
    srand((int)time(0));
    
    for (int i = 0; i < DistancesMatrix.size(); i++)
        for (int j = 0; j < DistancesMatrix.size(); j++)  {
                Summer=rand()%Power+1;
                DistancesMatrix[i][j]=AdjacencyMatrix[i][j]*Summer;
                DistancesMatrix[j][i]=DistancesMatrix[i][j];
            }
    cout<<"\t1.2 Distances matrix:\n";
    for (int i = 0; i < DistancesMatrix.size(); i++)    {
            cout<<"\t";
            for (int j = 0; j < DistancesMatrix.size(); j++)
                cout<<DistancesMatrix[i][j]<<", ";
            cout<<"\n";
        }
    return 0;
}

vector<vector<int>> Graph::ListOfEdges()
{
    for (int i = 0; i < NoVertex; i++)
        for (int j = i; j < NoVertex; j++)
            if (DistancesMatrix[i][j]!=0)
                EdgeList.push_back({DistancesMatrix[i][j],i,j});
    return EdgeList;
}

int Graph::GetNoVertex() {return NoVertex;}
int Graph::GetNoEdges()  {return NoEdges; }
vector<vector<int>> Graph::GetAdjacencyMatrix() {return AdjacencyMatrix;}
vector<vector<int>> Graph::GetDistancesMatrix() {return DistancesMatrix;}