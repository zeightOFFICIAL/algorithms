//kruskal.h 1128
#pragma once

#include <iostream>
#include <vector>

class DSU
{
    int* parent;
    int* rank;
public:
    DSU(int n);
    void unite_sets(int x, int y);
    int find_set(int i);
};

std::vector<std::vector<int>> MSTKruskal(std::vector<std::vector<int>> EdgeList, int NoVertex);