//graph.h 1115
#pragma once

#include <vector>
#include <string>

class Graph
{
protected:
    std::vector<std::vector<int>> adjacency_matrix;
    std::vector<std::vector<int>> distances_matrix;
    void ClearGraph();
public:
    explicit Graph();
    explicit Graph(Graph &grph);
    virtual ~Graph();

    void GenerateGraph(int number_of_vertices = 5, int number_of_edges = 7, int power = 10);
    void CustomGraph(int number_of_vertices = 5);
    void LoadGraph(std::string filename);

    void SaveGraph(std::string filename = "test.txt");

    void PrintAdjacencyMatrix();
    void PrintDistancesMatrix();
    void PrintEdgesList();

    std::vector<std::vector<int>> GetAdjacencyMatrix();
    std::vector<std::vector<int>> GetDistancesMatrix();
    std::vector<std::vector<int>> GetEdgesList();
};