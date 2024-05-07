#pragma once
#include <string>
#include <vector>


class Graph {
private:
    int nodesAmount;
    std::vector<std::vector<int>> consequentsList;
    std::vector<std::vector<int>> matrix;
    std::vector<std::pair<int, int>> table;

    void createGraphUser(int nodesAmount);
    void createGraphGenerate(int nodesAmount, int saturation);

public:
    explicit Graph(const std::string& argument);
    void createMatrixFromList();

    std::string type;
    std::vector<std::vector<int>>* getList();
    std::vector<std::vector<int>>* getMatrix();
    std::vector<std::pair<int, int>>* getTable();
};

