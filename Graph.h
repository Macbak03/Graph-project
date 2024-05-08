#pragma once
#include <string>
#include <vector>


class Graph {
private:
    int nodesAmount{};
    std::vector<std::vector<int>> matrix;
    std::vector<std::pair<int, int>> table;

    void createGraphUser();
    void createGraphGenerate(int saturation);

    void createMatrixFromList();
    void createListFromMatrix();
    void createTableFromList();
    void createTableFromMatrix();
public:
    std::vector<std::vector<int>> consequentsList;
    const static std::string argumentUser;
    const static std::string argumentGenerated;

    explicit Graph(const std::string& argument);
    void handleType(const std::string &argument);
    
    int getSize();

    std::string type;
    std::vector<std::vector<int>>* getList();
    std::vector<std::vector<int>>* getMatrix();
    std::vector<std::pair<int, int>>* getTable();
    
    std::vector<int> getNeighbors(int node);
};
