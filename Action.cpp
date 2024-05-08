#include "Action.h"
#include <iostream>
#include <utility>
#include <iomanip>
#include <queue>

using namespace std;

Action::Action(Graph *graph, std::string argument) : graph(graph), argument(std::move(argument)) {}

int Action::handleAction() {
    string actionName;
    bool keepRunning = true;
    while (keepRunning) {
        cout << "action>";
        cin >> actionName;

        if (cin.eof()) {
            break;
        }

        int actionType = checkActionType(actionName);
        switch (actionType) {
            case 1: { //Help
                showHelp();
                break;
            }
            case 2: { //Print
                print();
                break;
            }
            case 3: { //Find
                find();
                break;
            }
            case 4: { //BFS
                if (graph->type == "list" || graph->type == "table") {
                    bfsList();
                } else if (graph->type == "matrix") {
                    bfsMatrix();
                }
                break;
            }
            case 5: { //DFS
                break;
            }
            case 6: { //Export
                break;
            }
            case 7: { //Sort

            }
            case 8: { //Sort2
                break;
            }
            case 9: {
                keepRunning = false;
                break;
            }
            default: {
                cout << "Invalid action. Type Help for action list.\n";
                break;
            }
        }
    }
    return 0;
}

int Action::checkActionType(const std::string &action) {
    if (action == "Help") {
        return 1;
    } else if (action == "Print") {
        return 2;
    } else if (action == "Find") {
        return 3;
    } else if (action == "BFS") {
        return 4;
    } else if (action == "DFS") {
        return 5;
    } else if (action == "Export") {
        return 6;
    } else if (action == "Sort") {
        return 7;
    } else if (action == "Sort2") {
        return 8;
    } else if (action == "Exit") {
        return 9;
    } else {
        return -1;
    }
}

void Action::showHelp() {
    int width = 15;
    cout << left;
    cout << setw(width) << "Help" << "Show this message\n";
    cout << setw(width) << "Print" << "Print the graph in chosen type\n";
    cout << setw(width) << "Find" << "Finds the edge in graph\n";
    cout << setw(width) << "BFS" << "Do breath-first search\n";
    cout << setw(width) << "DFS" << "Do depth-first search\n";
    cout << setw(width) << "Export" << "Export the graph to tikzpicture\n";
    cout << setw(width) << "Sort" << "Sort graph using Kahn's algorithm\n";
    cout << setw(width) << "Sort2" << "Sort graph using Tarjan's algorithm\n";
    cout << setw(width) << "Exit" << "Exits the program\n";
}

void Action::print() {
    if (graph->type == "list") {
        printList();
    } else if (graph->type == "matrix") {
        printMatrix();
    } else if (graph->type == "table") {
        printTable();
    }
}

void Action::printMatrix() {
    for (const auto &row: *graph->getMatrix()) {
        for (int elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

void Action::printList() {
    vector<vector<int>> list = *graph->getList();
    for (int i = 0; i < list.size(); i++) {
        cout << i + 1 << " - ";
        for (int j: list[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Action::printTable() {
    for (auto &edge: *graph->getTable()) {
        cout << "(" << edge.first << ", " << edge.second << ")" << endl;
    }
}

void Action::find() {
    int from, to;
    cout << "from>";
    cin >> from;
    cout << "to>";
    cin >> to;

    bool edgeFound = false;

    for (auto &edge: *graph->getTable()) {
        if (edge.first == from && edge.second == to) {
            cout << "Edge (" << from << ", " << to << ") exists in the Graph!" << endl;
            edgeFound = true;
            break;
        }
    }

    if (!edgeFound) {
        cout << "Edge (" << from << "," << to << ") does not exists in the Graph!" << endl;
    }
}

void Action::bfsList() {
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

void Action::bfsMatrix() {
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
