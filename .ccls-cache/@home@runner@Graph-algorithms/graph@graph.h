#include <iostream>
#include <vector>

#pragma once

class Graph
{
private:
    int number_of_vertices;
    int number_of_edges;
protected:
    std::vector<std::vector<int>> adjacency_matrix;
    std::vector<std::vector<int>> distances_matrix;
public:
    explicit Graph();
    virtual ~Graph();

    void GenerateGraph(int number_of_vertices, int number_of_edges, int power);
    void LoadGraph(std::string filename);
    void SaveGraph(std::string filename);
    void ClearGraph();

    void PrintAdjacencyMatrix();
    void PrintDistancesMatrix();
    void PrintEdgesList();

    int GetNumberVertices();
    int GetNumberEdges();
    std::vector<std::vector<int>> GetAdjacencyMatrix();
    std::vector<std::vector<int>> GetDistancesMatrix();
    std::vector<std::vector<int>> GetEdgesList();
};