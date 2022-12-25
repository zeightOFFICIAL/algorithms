//graph.h 1122
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

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

Graph::Graph() {}
Graph::Graph(Graph &grph)
{
    adjacency_matrix = grph.GetAdjacencyMatrix();
    distances_matrix = grph.GetDistancesMatrix();
}
Graph::~Graph() {}

void Graph::GenerateGraph(int number_of_vertices, int number_of_edges, int power)
{
    Graph::ClearGraph();
    adjacency_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    distances_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    int each_edge = 0, summer_for_distance = 1, start_point, end_point;
    srand((int)time(0));
    while (each_edge < number_of_edges) {
        start_point = rand() % (adjacency_matrix.size());
        end_point = rand() % (adjacency_matrix.size());
        if ((adjacency_matrix[start_point][end_point] != 1) && (start_point != end_point)) {
            adjacency_matrix[start_point][end_point] = 1;
            adjacency_matrix[end_point][start_point] = 1;
            each_edge++;
        }
    }
    srand((int)time(0));
    for (int row = 0; row < distances_matrix.size(); row++) {
        for (int col = 0; col < distances_matrix.size(); col++) {
            summer_for_distance = rand() % power + 1;
            distances_matrix[row][col] = adjacency_matrix[row][col] * summer_for_distance;
            distances_matrix[col][row] = adjacency_matrix[row][col] * summer_for_distance;
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
        adjacency_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
        distances_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
        for (int row = 0; row < number_of_vertices; row++) {
            for (int col = 0; col < number_of_vertices; col++) {
                file >> distances_matrix[row][col];
                adjacency_matrix[row][col] = static_cast<bool>(distances_matrix[row][col]);
                count_edges += static_cast<bool>(distances_matrix[row][col]);
            }
        }
    }
    file.close();
}
void Graph::CustomGraph(int number_of_vertices)
{
    Graph::ClearGraph();
    adjacency_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    distances_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    int count_edge = 0, this_edge = 0;
    for (int row = 0; row < number_of_vertices; row++) {
        for (int col = row + 1; col < number_of_vertices; col++) {
            std::cout << "Input value of edge " << row << " -> " << col << ":";
            std::cin >> this_edge;
            if (this_edge != 0) {
                distances_matrix[row][col] = this_edge;
                distances_matrix[col][row] = this_edge;
                adjacency_matrix[row][col] = static_cast<bool>(distances_matrix[row][col]);
                adjacency_matrix[col][row] = static_cast<bool>(distances_matrix[col][row]);
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
        file << distances_matrix.size() << "\n";
        for (int row = 0; row < distances_matrix.size(); row++) {
            for (int col = 0; col < distances_matrix.size(); col++) {
                file << distances_matrix[row][col] << " ";
            }
            file << "\n";
        }
    }
    file.close();
}

void Graph::ClearGraph() {
    distances_matrix.clear();
    adjacency_matrix.clear();
}

void Graph::PrintAdjacencyMatrix()
{
    std::cout<<"Adjacency matrix:\n";
    for (int row = 0; row < adjacency_matrix.size(); row++) {
        std::cout << "\t";
        for (int col = 0; col < adjacency_matrix[row].size(); col++) {
            std::cout << std::setw(3) << std::left << adjacency_matrix[row][col];
        }
        std::cout << "\n";
    }
}
void Graph::PrintDistancesMatrix()
{
    std::cout<<"Distances matrix:\n";
    for (int row = 0; row < distances_matrix.size(); row++) {
        std::cout << "\t";
        for (int col = 0; col < distances_matrix.size(); col++) {
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
    for (int row = 0; row < distances_matrix.size(); row++)
        for (int col = row; col < distances_matrix.size(); col++)
            if (distances_matrix[row][col] != 0) {
                edges_list.push_back({ distances_matrix[row][col],row,col });
            }
    return edges_list;
}
std::vector<std::vector<int>> Graph::GetAdjacencyMatrix() {return adjacency_matrix;}
std::vector<std::vector<int>> Graph::GetDistancesMatrix() {return distances_matrix;}