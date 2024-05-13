#pragma once

#include <functional>
#include "Graph.h"

class Traverser {
private:
    Graph* graph;
    int nodesAmount;
    static void dfs(int node, std::vector<bool>& visited, const std::function<void(int, std::vector<bool>&)>& visitNeighbor);
public:
    explicit Traverser(Graph* graph);

    void bfsList();
    void bfsMatrix();
    void bfsTable();

    void dfsList();
    void dfsMatrix();
    void dfsTable();

};

