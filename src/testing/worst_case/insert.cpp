#include "insert.hpp"
#include <queue>

#include <iostream>

WorstInsertTester::WorstInsertTester(int count) : InsertTester(count) {} 

TesterData WorstInsertTester::test() {
    std::vector<int> input(m_count);
    for(int i = 0; i < m_count; i ++)
        input[i] = i;

    TesterData data; 
    AVLTree tree; 

    data.startTime = std::chrono::steady_clock::now();
    for (int i : input)
        tree.insert(i);
    data.endTime = std::chrono::steady_clock::now();
    std::cout << "WorstIns " << tree.unbalancedCnt << '\n';

    return data;
}
