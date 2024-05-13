#include "KahnSort.h"
#include "queue"
#include <iostream>

using namespace std;

KahnSort::KahnSort(Graph *graph) : Sorter(graph) {}

void KahnSort::kahnSortList() {
    vector<vector<int>> list = *graph->getList();
    vector<int> indegree(nodesAmount);
    queue<int> queue;
    vector<int> result;

    for (int i = 0; i < nodesAmount; i++) {
        for (auto it : list[i]) {
            indegree[it-1]++;
        }
    }

    for (int i = 0; i < nodesAmount; i++) {
        if (indegree[i] == 0) {
            queue.push(i+1);
        }
    }

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        result.push_back(node);

        for (auto it : list[node-1]) {
            indegree[it-1]--;

            if (indegree[it-1] == 0)
                queue.push(it);
        }
    }

    printKahn(result);
}

void KahnSort::kahnSortMatrix() {
    vector<vector<int>> matrix = *graph->getMatrix();
    vector<int> indegree(nodesAmount, 0);
    queue<int> queue;
    vector<int> result;

    for (int i = 0; i < nodesAmount; ++i) {
        for (int j = 0; j < nodesAmount; ++j) {
            if (matrix[j][i] > 0) {
                indegree[i]++;
            }
        }
    }

    for (int i = 0; i < nodesAmount; i++) {
        if (indegree[i] == 0) {
            queue.push(i+1);
        }
    }

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        result.push_back(node);

        for (int j = 0; j < nodesAmount; j++) {
            if (matrix[node-1][j] > 0) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    queue.push(j+1);
                }
            }
        }
    }

    printKahn(result);
}

void KahnSort::kahnSortTable() {
    vector<pair<int, int>> table = *graph->getTable();
    vector<int> indegree(nodesAmount, 0);
    queue<int> queue;
    vector<int> result;

    for (const auto& edge : table) {
        indegree[edge.second-1]++;
    }

    for (int i = 0; i < nodesAmount; i++) {
        if (indegree[i] == 0) {
            queue.push(i+1);
        }
    }

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        result.push_back(node);

        for (const auto& edge : table) {
            if (edge.first == node) {
                indegree[edge.second-1]--;
                if (indegree[edge.second-1] == 0) {
                    queue.push(edge.second);
                }
            }
        }
    }

    printKahn(result);
}

void KahnSort::printKahn(vector<int> &result) const {
    if (result.size() != nodesAmount) {
        cout << "Error: graph has at least one cycle\n" << endl;
        return;
    }

    cout << "Topological Sorting: ";
    for (int v : result) {
        cout << v << " ";
    }
    cout << endl;
}
