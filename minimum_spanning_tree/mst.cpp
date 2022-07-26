#include <vector>
#include <iostream>
#include <iomanip>
#include "limits.h"

#include "mst.h"
#include "kruskal.h"

Mst::Mst() { }
Mst::Mst(Graph &grph) 
{
    distances_matrix = grph.GetDistancesMatrix();
    adjacency_matrix = grph.GetAdjacencyMatrix();
}
Mst::~Mst() { }

std::vector<std::vector<int>> Mst::MstKruskall()
{
    if (distances_matrix.size() <= 0)
        std::cout << "the matrix is undefined" << "\n";
    else
    {
        mst_table = MSTKruskal(GetEdgesList(), distances_matrix.size());
        return mst_table;
    }
}

void Mst::MstPrintTable()
{
    int number_of_vertices = distances_matrix.size();
    std::cout<<"Minimum spanning tree matrix:\n";
    for (int l = 0; l < mst_table.size(); l++) {
        std::cout << "\t" << std::setw(2) << std::left << mst_table[l][0] << "- " << std::left << std::setw(2) << mst_table[l][1] << std::setw(3) << " weight " << mst_table[l][2] << "\n";
    }
    std::cout << "\n";
}