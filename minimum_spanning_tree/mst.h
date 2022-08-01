//mst.h 1126
#pragma once

#include <vector>
#include "../graph/graph.h"

class Mst: public Graph
{
private:
    std::vector<std::vector<int>> mst_table;
public:
    explicit Mst();
    explicit Mst(Graph &grph);
    virtual ~Mst();

    std::vector<std::vector<int>> MstKruskall();
    std::vector<std::vector<int>> MstPrim();
    std::vector<std::vector<int>> MstRedelete();

    void MstPrintTable();
    std::vector<std::vector<int>> GetVector();
};