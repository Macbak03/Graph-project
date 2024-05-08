#pragma once
#include "Graph.h"

class Sorter {
private:
    Graph* graph;

public:
    explicit Sorter(Graph* graph);

    void kahnSort();
    void TarjanSort();
};

