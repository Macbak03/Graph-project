#include "Action.h"
#include "Print.h"
#include "Traverser.h"
#include "Sorter.h"
#include <iostream>
#include <utility>
#include <iomanip>

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
                auto* print = new Print(graph);
                print->print();
                delete print;
                break;
            }
            case 3: { //Find
                find();
                break;
            }
            case 4: { //BFS
                auto* traverser = new Traverser(graph);
                if (graph->type == "list" || graph->type == "table") {
                    traverser->bfsList();
                } else if (graph->type == "matrix") {
                    traverser->bfsMatrix();
                }
                delete traverser;
                break;
            }
            case 5: { //DFS
                auto* traverser = new Traverser(graph);
                if (graph->type == "list" || graph->type == "table") {
                    traverser->dfsList();
                } else if (graph->type == "matrix") {
                    traverser->dfsMatrix();
                }
                delete traverser;
                break;
            }
            case 6: { //Export
                break;
            }
            case 7: { //Kahn
                auto* sorter = new Sorter(graph);
                sorter->kahnSort();
                delete sorter;
                break;
            }
            case 8: { //Tarjan
                auto* sorter = new Sorter(graph);
                sorter->TarjanSort();
                delete sorter;
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
    } else if (action == "Kahn") {
        return 7;
    } else if (action == "Tarjan") {
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
    cout << setw(width) << "Kahn" << "Sort graph using Kahn's algorithm\n";
    cout << setw(width) << "Tarjan" << "Sort graph using Tarjan's algorithm\n";
    cout << setw(width) << "Exit" << "Exits the program\n";
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


