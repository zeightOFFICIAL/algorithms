#include <iostream>
#include <vector>

#pragma once

class Graph
{
private:
    int NoVertex;
    int NoEdges;
protected:
    std::vector<std::vector<int>> AdjacencyMatrix;
    std::vector<std::vector<int>> DistancesMatrix;
public:
    explicit Graph(int NoVertex = 5, int NoEdges = 7);
    virtual ~Graph();

    int GenerateGraph(int Power);
    //void PrintGraphText();
    //void PrintGraphConsole();
    //void ClearGraph();

    int GetNoVertex();
    int GetNoEdges();
    std::vector<std::vector<int>> GetAdjacencyMatrix();
    std::vector<std::vector<int>> GetDistancesMatrix();

    //void Tool_ClearTxt();
};