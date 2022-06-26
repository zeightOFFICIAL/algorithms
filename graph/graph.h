//graph.h 1110
#pragma once

#include <vector>

class Graph
{
private:
    std::vector<std::vector<int>> adjacency_matrix;
    std::vector<std::vector<int>> distances_matrix;
public:
    explicit Graph();
    virtual ~Graph();

    void GenerateGraph(int number_of_vertices = 5, int number_of_edges = 10, int power = 10);
    void CustomGraph(int number_of_vertices = 5);
    void LoadGraph(std::string filename);

    void SaveGraph(std::string filename = "test.txt");
    void ClearGraph();

    void PrintAdjacencyMatrix();
    void PrintDistancesMatrix();
    void PrintEdgesList();

    std::vector<std::vector<int>> GetAdjacencyMatrix();
    std::vector<std::vector<int>> GetDistancesMatrix();
    std::vector<std::vector<int>> GetEdgesList();
};