//kruskal.h 1118
#pragma once

#include <iostream>
#include <vector>

class DSU
{
    int* parent;
    int* rank;
public:
    DSU(int n);
    void unite(int x, int y);
    int find(int i);
};

std::vector<std::vector<int>> MSTKruskal(std::vector<std::vector<int>> EdgeList, int NoVertex);