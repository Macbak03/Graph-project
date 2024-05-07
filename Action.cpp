#include "Action.h"
#include <iostream>

using namespace std;

Action::Action(Graph *graph) : graph(graph) {}

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
                //showHelp();
                break;
            }
            case 2: { //Print
                print();
                break;
            }
            case 3: { //Find

                break;
            }
            case 4: { //BFS

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
    } else if (action == "BSF") {
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

void Action::print() {
    if (graph->type == "list") {

    } else if (graph->type == "matrix") {
        printMatrix();

    } else if (graph->type == "table") {

    }
}

void Action::printMatrix() {
    graph->createMatrixFromList();
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
        for (int j : list[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Action::printTable() {

}
