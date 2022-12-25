//spg.h 1115
#pragma once

#include <vector>
#include "../graph.h"

#include "spg.h"
#include "dijkstra.h"
#include "floyd_warshall.h"
#include "johnson.h"

class Spg: public Graph
{
private:
    std::vector<std::vector<int>> spg_table;
public:
    explicit Spg();
    explicit Spg(Graph &grph);
    virtual ~Spg();

    std::vector<std::vector<int>> SpgDijstra();
    std::vector<std::vector<int>> SpgFloyd();
    std::vector<std::vector<int>> SpgJohnson();

    void SpgPrintTable();
    std::vector<std::vector<int>> GetTable();
};

Spg::Spg() { }
Spg::Spg(Graph &grph) 
{
    distances_matrix = grph.GetDistancesMatrix();
    adjacency_matrix = grph.GetAdjacencyMatrix();
}
Spg::~Spg() { }

std::vector<std::vector<int>> Spg::SpgDijstra()
{
    if (distances_matrix.size() <= 0)
        std::cout << "the matrix is undefined" << "\n";
    else
    {
        spg_table = SPGDijkstraTable(distances_matrix);
        return spg_table;
    }
}
std::vector<std::vector<int>> Spg::SpgFloyd()
{
    if (distances_matrix.size() <= 0)
        std::cout << "the matrix is undefined" << "\n";
    else
    {
        spg_table = SPGFloydTable(distances_matrix);
        return spg_table;
    }
}
std::vector<std::vector<int>> Spg::SpgJohnson()
{
    if (distances_matrix.size() <= 0)
        std::cout << "the matrix is undefined" << "\n";
    else
    {
        spg_table = SPGJohnsonTable(distances_matrix);
        return spg_table;
    }
}

void Spg::SpgPrintTable()
{
    int number_of_vertices = distances_matrix.size();
    std::cout<<"Shortest path matrix:\n";
    for (int j = 0; j < number_of_vertices; j++) {
        std::cout << "\t";
        for (int l = 0; l < number_of_vertices; l++) {
            std::cout << std::setw(3) << std::left << spg_table[j][l];
        }
        std::cout << "\n";
    }
}