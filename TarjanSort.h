#pragma once


#include "Sorter.h"

class TarjanSort : public Sorter{
private:
    enum NodeState{UNMARKED, TEMPORARY, PERMANENT};
    std::vector<NodeState> states;


    bool visit(int n, std::stack<int>& stack, std::vector<std::vector<int>>& list);
    bool visitMatrix(int n, std::stack<int> &stack, std::vector<std::vector<int>>& matrix);
    bool visitEdges(int n, std::stack<int> &stack, std::vector<std::pair<int, int>>& table);


    static void print(std::stack<int> &stack);
public:
    explicit TarjanSort(Graph *graph);
    void tarjanSortList();
    void tarjanSortMatrix();
    void tarjanSortTable();

};

