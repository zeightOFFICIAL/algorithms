#include <vector>
#include <iostream>
#include <iomanip>
#include "limits.h"

#include "mst.h"
#include "kruskal.h"
#include "prim.h"
#include "reverse_delete.h"

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
        mst_table = MSTKruskal(GetEdgesList(), adjacency_matrix.size());
        return mst_table;
    }
}
std::vector<std::vector<int>> Mst::MstPrim()
{
    if (distances_matrix.size() <= 0)
        std::cout << "the matrix is undefined" << "\n";
    else
    {
        mst_table = MSTPrim(distances_matrix);
        return mst_table;
    }
}
std::vector<std::vector<int>> Mst::MstRedelete()
{
    if (distances_matrix.size() <= 0)
        std::cout << "the matrix is undefined" << "\n";
    else
    {
        mst_table = MSTReverseDelete(GetEdgesList(), adjacency_matrix.size());
        return mst_table;
    }
}

void Mst::MstPrintTable()
{
    int number_of_vertices = distances_matrix.size();
    std::cout<<"Minimum spanning tree matrix:\n";
    int min_cost = 0;
    for (int l = 0; l < mst_table.size(); l++) {
        std::cout << "\t" << std::setw(2) << std::left << mst_table[l][0] << "- " << std::left << std::setw(2) << mst_table[l][1] << std::setw(3) << " weight " << mst_table[l][2] << "\n";
        min_cost += mst_table[l][2];
    }
    std::cout << "MST cost: " << min_cost << "\n";
}