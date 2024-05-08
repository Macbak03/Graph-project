#pragma once
#include "Graph.h"

class Action {
private:
    Graph* graph;
    std::string argument;

    static int checkActionType(const std::string& action);

    static void showHelp();

    void find();

    void exportToTikZ();
public:
    explicit Action(Graph* graph, std::string  argument);
    int handleAction();
};

