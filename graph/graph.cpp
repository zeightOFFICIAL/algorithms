#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>

#include "graph.h"

Graph::Graph() 
{
    number_of_vertices = 0;
    number_of_edges = 0;
}

Graph::~Graph() {}

void Graph::GenerateGraph(int number_of_vertices, int number_of_edges, int power)
{
    Graph::ClearGraph();
    adjacency_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    distances_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
    int each_edge = 0, summer_for_distance = 1, start_point, end_point;
    srand((int)time(0));
    while (each_edge < number_of_edges)  {
            start_point = rand()%(adjacency_matrix.size());
            end_point = rand()%(adjacency_matrix.size());
            if ((adjacency_matrix[start_point][end_point] != 1) && (start_point != end_point)) {
                adjacency_matrix[start_point][end_point] = 1;
                adjacency_matrix[end_point][start_point] = 1;
                each_edge++;
            }
        }
    srand((int)time(0));
    for (int row = 0; row < distances_matrix.size(); row++)
        for (int col = 0; col < distances_matrix.size(); col++) {
            summer_for_distance = rand() % power + 1;
            distances_matrix[row][col] = adjacency_matrix[row][col] * summer_for_distance;
            distances_matrix[col][row] = adjacency_matrix[row][col] * summer_for_distance;
        }
}

void Graph::LoadGraph(std::string filename)
{
    Graph::ClearGraph();
    int count_edges = 0;
    std::ifstream file;
    file.open(filename);
	if (!file)
        std::cout << "No such file.";
	else  {
            file >> number_of_vertices;
            adjacency_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
            distances_matrix.resize(number_of_vertices, std::vector<int>(number_of_vertices, 0));
            for (int row = 0; row < number_of_vertices; row++)
                for (int col = 0; col < number_of_vertices; col++) {
                        file >> distances_matrix[row][col];
                        adjacency_matrix[row][col]=static_cast<bool>(distances_matrix[row][col]);
                        count_edges += static_cast<bool>(distances_matrix[row][col]);
                    }
        }
    number_of_edges = count_edges/2;
    file.close();
}

void Graph::SaveGraph(std::string filename)
{
    std::ofstream file;
    file.open(filename, std::ios::trunc);
	if (!file)
        std::cout << "No such file.";
	else  {
        file << distances_matrix.size() << "\n";
        for (int i = 0; i < distances_matrix.size(); i++) {
            for (int j = 0; j < distances_matrix.size(); j++)
                    file << distances_matrix[i][j] << " ";
                file <<"\n";
            }
        }
    file.close();
}

void Graph::ClearGraph() {
    distances_matrix.clear();
    adjacency_matrix.clear();
    number_of_vertices = 0;
    number_of_edges = 0;
}

void Graph::PrintAdjacencyMatrix()
{
    std::cout<<"\tAdjacency matrix:\n";
    for (int i = 0; i < adjacency_matrix.size(); i++)  {
        std::cout<<"\t";
            for (int j = 0; j < adjacency_matrix[i].size(); j++)
                std::cout<<adjacency_matrix[i][j]<<", ";
            std::cout << "\n";
        }
}

void Graph::PrintDistancesMatrix()
{
    std::cout<<"\tDistances matrix:\n";
    for (int i = 0; i < distances_matrix.size(); i++)  {
        std::cout<<"\t";
            for (int j = 0; j < distances_matrix.size(); j++)
                std::cout<<distances_matrix[i][j]<<", ";
            std::cout<<"\n";
        }
}

void Graph::PrintEdgesList()
{
    std::vector<std::vector<int>> edges_list = GetEdgesList();
    for (int i = 0; i < number_of_edges; i++)
        std::cout << "I:" << i << "  " << edges_list[i][1] << " - " << edges_list[i][2] << " with weight " << edges_list[i][0] << "\n";
}

std::vector<std::vector<int>> Graph::GetEdgesList()
{
    std::vector<std::vector<int>> edges_list;
    for (int i = 0; i < number_of_vertices; i++)
        for (int j = i; j < number_of_vertices; j++)
            if (distances_matrix[i][j]!=0)
                edges_list.push_back({distances_matrix[i][j],i,j});
    return edges_list;
}

int Graph::GetNumberVertices() {return number_of_vertices;}
int Graph::GetNumberEdges()    {return number_of_edges;}
std::vector<std::vector<int>> Graph::GetAdjacencyMatrix() {return adjacency_matrix;}
std::vector<std::vector<int>> Graph::GetDistancesMatrix() {return distances_matrix;}