#include "Graph.h"
#include <iostream>
#include <sstream>

using namespace std;

Graph::Graph(const string &argument) {
    cout<<"type>";
    cin>>type;
    cout << "nodes>";
    cin >> nodesAmount;
    cin.ignore();

    consequentsList = vector<vector<int>>(nodesAmount);
    matrix = vector<vector<int>>(nodesAmount, vector<int>(nodesAmount, 0));


    if (argument == "--user-provided") {
        createGraphUser(nodesAmount);
    } else if (argument == "--generate") {
        cout << "saturation>";
        int saturation;
        cin>>saturation;
        createGraphGenerate(nodesAmount, saturation);
    }

}

void Graph::createGraphUser(int nodesAmount) {
    for (int i = 0; i < nodesAmount; ++i) {
        string line;
        cout << i + 1 << ">";
        getline(std::cin, line);
        istringstream iss(line);
        int successor;
        while (iss >> successor) {
            if (successor < 1 || successor > nodesAmount) {
                cout << "Invalid node value\n";
                return;
            }
            consequentsList[i].push_back(successor);
        }
    }
    for(int i = 0; i < consequentsList.size(); i++){
        cout << i+1 << " - ";
        for (int node : consequentsList[i]) {
            cout << node << " ";
        }
        cout<<endl;
    }
}

void Graph::createGraphGenerate(int nodesAmount, int saturation) {
    int maxEdges = nodesAmount * (nodesAmount - 1) / 2;
    int numberOfEdges = maxEdges * saturation / 100;

    srand(time(nullptr));

    while (numberOfEdges > 0) {
        int i = rand() % nodesAmount;
        int j = rand() % nodesAmount;
        if (i < j && matrix[i][j] == 0) {
            matrix[i][j] = 1;
            numberOfEdges--;
        }
    }

}

void Graph::createMatrixFromList() {
    for (int i = 0; i < nodesAmount; ++i) {
        for (int successor : consequentsList[i]) {
            matrix[i][successor-1] = 1;
        }
    }
}

std::vector<std::vector<int>>* Graph::getList() {
    return &consequentsList;
}

std::vector<std::vector<int>> *Graph::getMatrix() {
    return &matrix;
}

std::vector<std::pair<int, int>> *Graph::getTable() {
    return &table;
}
