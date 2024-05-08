#pragma once
#include "Graph.h"

class Print {
private:
    Graph* graph;

    void printMatrix();
    void printList();
    void printTable();
public:
    explicit Print(Graph* graph);
    void print();
};



