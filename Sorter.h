#pragma once

#include <stack>
#include <vector>
#include "Graph.h"

class Sorter {
private:
    Graph* graph;
    std::string argument;
    enum NodeState{UNMARKED, TEMPORARY, PERMANENT};
    std::vector<NodeState> states;

    bool visit(int n, std::stack<int>& stack, std::vector<std::vector<int>> consequentsList);


public:
    explicit Sorter(Graph* graph);

    void kahnSort();
    void TarjanSort();
};

