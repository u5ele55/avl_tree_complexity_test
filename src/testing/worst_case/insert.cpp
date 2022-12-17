#include "insert.hpp"
#include <queue>

#include <iostream>

WorstInsertTester::WorstInsertTester(int count) : InsertTester(count) {} 

TesterData WorstInsertTester::test() {
    std::vector<int> input(m_count);
    for(int i = 0; i < m_count; i ++)
        input[i] = 5;

    TesterData data; 
    AVLTree tree; 

    data.startTime = std::chrono::steady_clock::now();
    for (int i : input)
        tree.insert(i);
    data.endTime = std::chrono::steady_clock::now();
    data.smallRotationQuantity = tree.smallRotations;
    
    return data;
}
