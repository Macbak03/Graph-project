#pragma once


#include "Sorter.h"

class KahnSort : public Sorter {
private:
    void printKahn(std::vector<int> &result) const;

public:
    explicit KahnSort(Graph* graph);
    void kahnSortList();
    void kahnSortMatrix();
    void kahnSortTable();

};


