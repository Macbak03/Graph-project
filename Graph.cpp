#include "Graph.h"
#include "InvalidDataException.h"
#include <iostream>
#include <sstream>

using namespace std;


const string Graph::argumentUser = "--user-provided";
const string Graph::argumentGenerated = "--generate";
const string Graph::typeList = "list";
const string Graph::typeMatrix = "matrix";
const string Graph::typeTable = "table";

Graph::Graph(const string &argument) {
    cout<<"type>";
    cin>>type;
    if(type != typeList && type != typeMatrix && type != typeTable){
        throw InvalidDataException("Invalid graph type. Correct types are: list, matrix, table");
    }
    cout << "nodes>";
    cin >> nodesAmount;
    cin.ignore();

    consequentsList = vector<vector<int>>(nodesAmount);
    matrix = vector<vector<int>>(nodesAmount, vector<int>(nodesAmount, 0));
    table = vector<pair<int,int>>();

    if (argument == argumentUser) {
        createGraphUser();
    } else if (argument == argumentGenerated) {
        cout << "saturation>";
        int saturation;
        cin>>saturation;
        if(saturation < 1 || saturation > 100){
            throw InvalidDataException("saturation must be in range (0, 100>");
        }
        createGraphGenerate(saturation);
    }
    handleType(argument);

}

void Graph::createGraphUser() {
    for (int i = 0; i < nodesAmount; ++i) {
        string line;
        cout << i + 1 << ">";
        getline(std::cin, line);
        istringstream iss(line);
        int successor;
        int tmp = 0;
        while (iss >> successor) {
            if (successor < 1 || successor > nodesAmount) {
                throw InvalidDataException("Invalid node value");
            }
            if(successor < tmp){
                throw InvalidDataException("Nodes must be in ascending order");
            }
            tmp = successor;
            consequentsList[i].push_back(successor);
        }
    }
}

void Graph::handleType(const string &argument) {
    if(argument == argumentUser){
        createMatrixFromList();
        createTableFromList();
    } else if(argument == argumentGenerated){
        createListFromMatrix();
        createTableFromMatrix();
    }
}

void Graph::createGraphGenerate(int saturation) {
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


void Graph::createListFromMatrix() {
    for (int i = 0; i < nodesAmount; ++i) {
        for (int j = 0; j < nodesAmount; ++j) {
            if (matrix[i][j] == 1) {
                consequentsList[i].push_back(j+1);
            }
        }
    }
}

void Graph::createTableFromList() {
    for (int i = 0; i < nodesAmount; ++i) {
        for (int j : consequentsList[i]) {
            table.emplace_back(i+1, j);
        }
    }
}

void Graph::createTableFromMatrix() {
    for (int i = 0; i < nodesAmount; ++i) {
        for (int j = 0; j < nodesAmount; ++j) {
            if (matrix[i][j] == 1) {
                table.emplace_back(i+1, j+1);
            }
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
