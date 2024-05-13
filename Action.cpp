#include "Action.h"
#include "Print.h"
#include "Traverser.h"
#include "KahnSort.h"
#include "TarjanSort.h"
#include <iostream>
#include <utility>
#include <iomanip>
#include <stack>
#include <fstream>
#include <random>

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
                if (graph->type == Graph::typeList) {
                    traverser->bfsList();
                } else if (graph->type == Graph::typeMatrix) {
                    traverser->bfsMatrix();
                } else{
                    traverser->bfsTable();
                }
                delete traverser;
                break;
            }
            case 5: { //DFS
                auto* traverser = new Traverser(graph);
                if (graph->type == Graph::typeList) {
                    traverser->dfsList();
                } else if (graph->type == Graph::typeMatrix) {
                    traverser->dfsMatrix();
                } else{
                    traverser->dfsTable();
                }
                delete traverser;
                break;
            }
            case 6: { //Export
                exportToTikZ();
                break;
            }
            case 7: { //Kahn
                auto* kahnSort = new KahnSort(graph);
                if(graph->type == Graph::typeMatrix){
                    kahnSort->kahnSortMatrix();
                } else if (graph->type == Graph::typeList){
                    kahnSort->kahnSortList();
                } else{
                    kahnSort->kahnSortTable();
                }
                delete kahnSort;
                break;
            }
            case 8: { //Tarjan
                auto* tarjanSort = new TarjanSort(graph);
                if(graph->type == Graph::typeMatrix){
                    tarjanSort->tarjanSortMatrix();
                } else if (graph->type == Graph::typeList){
                    tarjanSort->tarjanSortList();
                } else{
                    tarjanSort->tarjanSortTable();
                }
                delete tarjanSort;
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

void Action::exportToTikZ() {
    vector<vector<int>> list = *graph->getList();
    int V = list.size();
    ofstream file("Graph");

    if (!file.is_open()) {
        cout << "Error: Cannot open file." << endl;
        return;
    }

    file << "\\input{name}\n";
    file << "\\documentclass{standalone}\n";
    file << "\\usepackage{tikz}\n";
    file << "\\begin{document}\n";
    file << "\\begin{tikzpicture}\n";

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(1.0, 10.0);

    for (int i = 0; i < V; ++i) {
        double offsetY = dis(gen);
        file << "\\node[shape=circle,draw=black] (" << i + 1 << ") at (" << i * 2 << "," << offsetY << ") {" << i + 1 << "};\n";
    }

    for (int u = 0; u < V; ++u) {
        for (int v : list[u]) {
            file << "\\path [->](" << u + 1 << ") edge (" << v << ");\n";
        }
    }

    file << "\\end{tikzpicture}\n";
    file << "\\end{document}\n";

    file.close();

    cout << "Graph has been exported to TikZ." << endl;
}

