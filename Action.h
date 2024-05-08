#pragma once
#include "Graph.h"

class Action {
private:
    Graph* graph;
    std::string argument;

    static int checkActionType(const std::string& action);

    void showHelp();

    void print();
    void printMatrix();
    void printList();
    void printTable();

    void find();

    void bfsList();
    void bfsMatrix();

    void dfs(int start);

public:
    explicit Action(Graph* graph, std::string  argument);
    int handleAction();
};

