#include "TarjanSort.h"
#include <iostream>

using namespace std;

TarjanSort::TarjanSort(Graph *graph) : Sorter(graph) {
    states = vector<NodeState>(nodesAmount, UNMARKED);
}

void TarjanSort::tarjanSortList() {
    vector<vector<int>> list = *graph->getList();
    stack<int> stack;
    for (int i = 0; i < list.size(); ++i) {
        if (states[i] == UNMARKED) {
            if (!visit(i, stack, list)) {
                cout << "Error: graph has at least one cycle\n";
                return;
            }
        }
    }
    print(stack);
}

void TarjanSort::tarjanSortMatrix() {
    vector<vector<int>> matrix = *graph->getMatrix();
    stack<int> stack;
    for (int i = 0; i < nodesAmount; ++i) {
        if (states[i] == UNMARKED) {
            if (!visitMatrix(i, stack, matrix)) {
                cout << "Error: graph has at least one cycle\n";
                return;
            }
        }
    }
    print(stack);
}



void TarjanSort::tarjanSortTable() {
    vector<pair<int, int>> table = *graph->getTable();
    stack<int> stack;
    for (int i = 0; i < nodesAmount; ++i) {
        if (states[i] == UNMARKED) {
            if (!visitEdges(i, stack, table)) {
                cout << "Error: graph has at least one cycle\n";
                return;
            }
        }
    }
    print(stack);
}

bool TarjanSort::visit(int n, stack<int> &stack, vector<vector<int>>& list) {
    if (states[n] == PERMANENT) return true;
    if (states[n] == TEMPORARY) return false;
    states[n] = TEMPORARY;
    for (int m: list[n]) {
        if (!visit(m-1, stack, list)) return false;
    }
    states[n] = PERMANENT;
    stack.push(n+1);
    return true;
}

bool TarjanSort::visitMatrix(int n, stack<int> &stack, vector<vector<int>>& matrix) {
    if (states[n] == PERMANENT) return true;
    if (states[n] == TEMPORARY) return false;
    states[n] = TEMPORARY;
    for (int j = 0; j < nodesAmount; j++) {
        if (matrix[n][j] > 0) {
            if (!visitMatrix(j, stack, matrix)) return false;
        }
    }
    states[n] = PERMANENT;
    stack.push(n + 1);
    return true;
}

bool TarjanSort::visitEdges(int n, stack<int> &stack, vector<pair<int, int>>& table) {
    if (states[n] == PERMANENT) return true;
    if (states[n] == TEMPORARY) return false;
    states[n] = TEMPORARY;
    for (auto& edge : table) {
        if (edge.first-1 == n) {
            if (!visitEdges(edge.second-1, stack, table)) return false;
        }
    }
    states[n] = PERMANENT;
    stack.push(n + 1);
    return true;
}

void TarjanSort::print(stack<int> &stack) {
    cout << "Topological Sorting: ";
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}
