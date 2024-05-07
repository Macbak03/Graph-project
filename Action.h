#pragma once
#include "Graph.h"

class Action {
private:
    Graph* graph;
    static int checkActionType(const std::string& action);
    void print();
    void printMatrix();
    void printList();
    void printTable();
public:
    explicit Action(Graph* graph);
    int handleAction();
};

