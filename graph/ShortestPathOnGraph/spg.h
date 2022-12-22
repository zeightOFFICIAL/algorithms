//spg.h 1115
#pragma once

#include <vector>
#include "../graph.h"

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