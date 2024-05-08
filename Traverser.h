#pragma once

#include <functional>
#include "Graph.h"

class Traverser {
private:
    Graph* graph;
    static void dfs(int node, std::vector<bool>& visited, const std::function<void(int, std::vector<bool>&)>& visitNeighbor);
public:
    explicit Traverser(Graph* graph);

    void bfsList();
    void bfsMatrix();

    void dfsList();
    void dfsMatrix();

};

