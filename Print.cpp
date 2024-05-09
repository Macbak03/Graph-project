#include "Print.h"
#include <iostream>

using namespace std;

Print::Print(Graph *graph) : graph(graph){}

void Print::print() {
    if (graph->type == Graph::typeList) {
        printList();
    } else if (graph->type == Graph::typeMatrix) {
        printMatrix();
    } else if (graph->type == Graph::typeTable) {
        printTable();
    }
}

void Print::printMatrix() {
    vector<vector<int>> matrix = *graph->getMatrix();
    cout<<"  | ";
    for(int i = 1; i<=matrix.size(); i++){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"--+-";
    for(int i = 1; i<2*matrix.size(); i++){
        cout<<"-";
    }
    cout<<endl;
    for (int i = 0; i<matrix.size(); i++) {
        cout<<i+1<<" | ";
        for (int j = 0; j<matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Print::printList() {
    vector<vector<int>> list = *graph->getList();
    for (int i = 0; i < list.size(); i++) {
        cout << i + 1 << " - ";
        for (int j: list[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Print::printTable() {
    for (auto &edge: *graph->getTable()) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }
}
