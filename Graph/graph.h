//graph.h 1122
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Graph
{
protected:
    std::vector<std::vector<int>> AdjacencyMatrix;
    std::vector<std::vector<int>> DistancesMatrix;
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

Graph::Graph() {}
Graph::Graph(Graph &grph)
{
    AdjacencyMatrix = grph.GetAdjacencyMatrix();
    DistancesMatrix = grph.GetDistancesMatrix();
}
Graph::~Graph() {}

void Graph::GenerateGraph(int number_of_vertices, int number_of_edges, int power)
{
    Graph::ClearGraph();
    AdjacencyMatrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    DistancesMatrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    int each_edge = 0, summer_for_distance = 1, start_point, end_point;
    srand((int)time(0));
    while (each_edge < number_of_edges) {
        start_point = rand() % (AdjacencyMatrix.size());
        end_point = rand() % (AdjacencyMatrix.size());
        if ((AdjacencyMatrix[start_point][end_point] != 1) && (start_point != end_point)) {
            AdjacencyMatrix[start_point][end_point] = 1;
            AdjacencyMatrix[end_point][start_point] = 1;
            each_edge++;
        }
    }
    srand((int)time(0));
    for (int row = 0; row < DistancesMatrix.size(); row++) {
        for (int col = 0; col < DistancesMatrix.size(); col++) {
            summer_for_distance = rand() % power + 1;
            DistancesMatrix[row][col] = AdjacencyMatrix[row][col] * summer_for_distance;
            DistancesMatrix[col][row] = AdjacencyMatrix[row][col] * summer_for_distance;
        }
    }
}
void Graph::LoadGraph(std::string filename)
{
    Graph::ClearGraph();
    int count_edges = 0, number_of_vertices;
    std::ifstream file;
    file.open(filename);
	if (!file)
        std::cout << "no such file";
    else {
        file >> number_of_vertices;
        AdjacencyMatrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
        DistancesMatrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
        for (int row = 0; row < number_of_vertices; row++) {
            for (int col = 0; col < number_of_vertices; col++) {
                file >> DistancesMatrix[row][col];
                AdjacencyMatrix[row][col] = static_cast<bool>(DistancesMatrix[row][col]);
                count_edges += static_cast<bool>(DistancesMatrix[row][col]);
            }
        }
    }
    file.close();
}
void Graph::CustomGraph(int number_of_vertices)
{
    Graph::ClearGraph();
    AdjacencyMatrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    DistancesMatrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    int count_edge = 0, this_edge = 0;
    for (int row = 0; row < number_of_vertices; row++) {
        for (int col = row + 1; col < number_of_vertices; col++) {
            std::cout << "Input value of edge " << row << " -> " << col << ":";
            std::cin >> this_edge;
            if (this_edge != 0) {
                DistancesMatrix[row][col] = this_edge;
                DistancesMatrix[col][row] = this_edge;
                AdjacencyMatrix[row][col] = static_cast<bool>(DistancesMatrix[row][col]);
                AdjacencyMatrix[col][row] = static_cast<bool>(DistancesMatrix[col][row]);
                count_edge++;
            }
        }
    }
}
void Graph::SaveGraph(std::string filename)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
	if (!file)
        std::cout << "no such file";
    else {
        file << DistancesMatrix.size() << "\n";
        for (int row = 0; row < DistancesMatrix.size(); row++) {
            for (int col = 0; col < DistancesMatrix.size(); col++) {
                file << DistancesMatrix[row][col] << " ";
            }
            file << "\n";
        }
    }
    file.close();
}

void Graph::ClearGraph() {
    DistancesMatrix.clear();
    AdjacencyMatrix.clear();
}

void Graph::PrintAdjacencyMatrix()
{
    std::cout<<"Adjacency matrix:\n";
    for (int row = 0; row < AdjacencyMatrix.size(); row++) {
        std::cout << "\t";
        for (int col = 0; col < AdjacencyMatrix[row].size(); col++) {
            std::cout << std::setw(3) << std::left << adjacency_matrix[row][col];
        }
        std::cout << "\n";
    }
}
void Graph::PrintDistancesMatrix()
{
    std::cout<<"Distances matrix:\n";
    for (int row = 0; row < DistancesMatrix.size(); row++) {
        std::cout << "\t";
        for (int col = 0; col < DistancesMatrix.size(); col++) {
            std::cout << std::setw(3) << std::left << distances_matrix[row][col];
        }
        std::cout << "\n";
    }
}
void Graph::PrintEdgesList()
{
    std::cout << "Edges list:\n";
    std::vector<std::vector<int>> edges_list = GetEdgesList();
    for (int each_edge = 0; each_edge < edges_list.size(); each_edge++) {
        std::cout << "\t";
        std::cout << "I:" << std::left << std::setw(3) << each_edge << " " << std::setw(3) << edges_list[each_edge][1] << " -  " << std::setw(3) << edges_list[each_edge][2] << " with weight " << std::setw(2) << edges_list[each_edge][0] << "\n";
    }
}

std::vector<std::vector<int>> Graph::GetEdgesList()
{
    std::vector<std::vector<int>> edges_list;
    for (int row = 0; row < DistancesMatrix.size(); row++)
        for (int col = row; col < DistancesMatrix.size(); col++)
            if (DistancesMatrix[row][col] != 0) {
                edges_list.push_back({ DistancesMatrix[row][col],row,col });
            }
    return edges_list;
}
std::vector<std::vector<int>> Graph::GetAdjacencyMatrix() {return AdjacencyMatrix;}
std::vector<std::vector<int>> Graph::GetDistancesMatrix() {return DistancesMatrix;}