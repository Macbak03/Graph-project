#include "Traverser.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

Traverser::Traverser(Graph *graph): graph(graph) {
    nodesAmount = graph->getList()->size();
}

void Traverser::bfsList() {
    vector<vector<int>> list = *graph->getList();
    vector<bool> visited(nodesAmount, false);
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
    vector<bool> visited(nodesAmount, false);
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

                for (int j = 0; j < nodesAmount; ++j) {
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


void Traverser::bfsTable() {
    vector<pair<int, int>> table = *graph->getTable();
    vector<bool> visited(nodesAmount, false);
    queue<int> queue;

    unordered_map<int, vector<int>> neighbors;
    for (const auto& edge : table) {
        neighbors[edge.first].push_back(edge.second);
    }

    cout << "Inline: ";

    for (int i = 0; i < nodesAmount; i++) {
        if (!visited[i]) {
            visited[i] = true;
            queue.push(i + 1);

            while (!queue.empty()) {
                int current = queue.front();
                queue.pop();

                cout << current << " ";

                for (int next : neighbors[current]) {
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

void Traverser::dfs(int node, vector<bool> &visited, const function<void(int, std::vector<bool> &)> &visitNeighbor) {
    visited[node-1] = true;
    cout << node<< " ";

    visitNeighbor(node-1, visited);
}

void Traverser::dfsList() {
    vector<vector<int>> list = *graph->getList();
    vector<bool> visited(nodesAmount, false);
    std::function<void(int, std::vector<bool>&)> visitNeighbor = [&](int node, std::vector<bool>& visited) {
        for (int neighbor : list[node]) {
            if (!visited[neighbor-1]) {
                dfs(neighbor, visited, visitNeighbor);
            }
        }
    };

    for (int i = 0; i < nodesAmount; ++i) {
        if (!visited[i]) {
            dfs(i+1, visited, visitNeighbor);
        }
    }
    cout<<endl;
}

void Traverser::dfsMatrix() {
    vector<vector<int>> matrix = *graph->getMatrix();
    vector<bool> visited(nodesAmount, false);
    function<void(int, std::vector<bool>&)> visitNeighbor;
    visitNeighbor = [&](int node, std::vector<bool>& visited) {
        for (int j = 0; j < matrix[node].size(); ++j) {
            if (matrix[node][j] == 1 && !visited[j]) {
                dfs(j+1, visited, visitNeighbor);
            }
        }
    };

    for (int i = 0; i < nodesAmount; ++i) {
        if (!visited[i]) {
            dfs(i+1, visited, visitNeighbor);
        }
    }
    cout<<endl;
}

void Traverser::dfsTable() {
    vector<pair<int, int>> table = *graph->getTable();
    vector<bool> visited(nodesAmount, false);
    function<void(int)> dfs = [&](int node) {
        cout << node << " ";
        visited[node - 1] = true;
        for (const auto& edge : table) {
            if (edge.first == node && !visited[edge.second - 1]) {
                dfs(edge.second);
            }
        }
    };

    for (int i = 0; i < nodesAmount; ++i) {
        if (!visited[i]) {
            dfs(i + 1);
        }
    }
    cout << endl;
}

