#include "Sorter.h"
#include <iostream>
#include <queue>

using namespace std;

Sorter::Sorter(Graph *graph) : graph(graph) {}

void Sorter::kahnSort() {
    vector<vector<int>> list = *graph->getList();
    int nodesAmount = list.size();
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

    if (result.size() != nodesAmount) {
        cout << "Error: graph has at least one cycle\n" << endl;
        return;
    }

    if(!result.empty()){
        cout << "Topological Sorting: ";
        for(int v : result){
            cout << v << " ";
        }
        cout << endl;
    }
}

void Sorter::TarjanSort() {
    vector<vector<int>> consequentsList = *graph->getList();
    states = vector<NodeState>(consequentsList.size(), UNMARKED);
    stack<int> stack;
    for (int i = 0; i < consequentsList.size(); ++i) {
        if (states[i] == UNMARKED) {
            if (!visit(i, stack, consequentsList)) {
                cout << "Error: graph has at least one cycle\n";
                return;
            }
        }
    }

    cout << "Topological Sorting: ";
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

bool Sorter::visit(int n, stack<int> &stack, vector<vector<int>> consequentsList) {
    if (states[n] == PERMANENT) return true;
    if (states[n] == TEMPORARY) return false;
    states[n] = TEMPORARY;
    for (int m: consequentsList[n]) {
        if (!visit(m-1, stack, consequentsList)) return false;
    }
    states[n] = PERMANENT;
    stack.push(n+1);
    return true;
}
