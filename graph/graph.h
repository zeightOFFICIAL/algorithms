//graph.h 1106
/*
* Graph class and a set of methods
* for creating (generating) and deleting:
*   explicit constructor
*   virtual destructor
*   create custom graph
*   graph generator
*   load graph from file
*   save graph to file
*   clear the graph
* for printing:
*   print adjacency matrix
*   print distances matrix
*   print edges list
* getters: 
*   get number of vertices
*   get number of edges
*   get adjacency matrix
*   get distances matrix
*   get edges list
*/
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

    void GenerateGraph(int number_of_vertices = 5, int number_of_edges = 15, int power = 10);
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