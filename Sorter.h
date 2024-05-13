#pragma once

#include <stack>
#include <vector>
#include "Graph.h"

class Sorter {
protected:
    Graph* graph;
    int nodesAmount;
public:
    explicit Sorter(Graph* graph);
};

