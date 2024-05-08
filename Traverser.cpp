#include "Traverser.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

Traverser::Traverser(Graph *graph): graph(graph) {}

void Traverser::bfsList() {
    vector<vector<int>> list = *graph->getList();
    vector<bool> visited(list.size(), false);
    queue<int> queue;

    cout << "Inline: ";

    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            queue.push(i + 1);

            while (!queue.empty()) {
                int current = queue.front();
                queue.pop();

                cout << current << " ";

                for (int next: list[current - 1]) {
                    if (!visited[next - 1]) {
                        visited[next - 1] = true;
                        queue.push(next);
                    }
                }
            }
        }
    }
    cout << endl;
}

void Traverser::bfsMatrix() {
    vector<vector<int>> matrix = *graph->getMatrix();
    int n = matrix.size();
    vector<bool> visited(n, false);
    queue<int> queue;

    cout << "Inline: ";

    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            queue.push(i + 1);

            while (!queue.empty()) {
                int current = queue.front();
                queue.pop();

                cout << current << " ";

                for (int j = 0; j < n; ++j) {
                    if (matrix[current - 1][j] == 1 &&
                        !visited[j]) {
                        visited[j] = true;
                        queue.push(j + 1);
                    }
                }
            }
        }
    }
    cout << endl;
}



void Traverser::dfs(int node, vector<bool> &visited, const function<void(int, std::vector<bool> &)> &visitNeighbor) {
    visited[node-1] = true;
    cout << node<< " ";

    visitNeighbor(node-1, visited);
}

void Traverser::dfsList() {
    vector<vector<int>> consequentsList = *graph->getList();
    vector<bool> visited(consequentsList.size(), false);
    std::function<void(int, std::vector<bool>&)> visitNeighbor = [&](int node, std::vector<bool>& visited) {
        for (int neighbor : consequentsList[node]) {
            if (!visited[neighbor-1]) {
                dfs(neighbor, visited, visitNeighbor);
            }
        }
    };

    for (int i = 0; i < consequentsList.size(); ++i) {
        if (!visited[i]) {
            dfs(i+1, visited, visitNeighbor);
        }
    }
    cout<<endl;
}

void Traverser::dfsMatrix() {
    vector<vector<int>> matrix = *graph->getMatrix();
    vector<bool> visited(matrix.size(), false);
    function<void(int, std::vector<bool>&)> visitNeighbor;
    visitNeighbor = [&](int node, std::vector<bool>& visited) {
        for (int j = 0; j < matrix[node].size(); ++j) {
            if (matrix[node][j] == 1 && !visited[j]) {
                dfs(j+1, visited, visitNeighbor);
            }
        }
    };

    for (int i = 0; i < matrix.size(); ++i) {
        if (!visited[i]) {
            dfs(i+1, visited, visitNeighbor);
        }
    }
    cout<<endl;
}

