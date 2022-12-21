#include "insert.hpp"
#include <queue>

#include <iostream>


WorstInsertTester::WorstInsertTester(int elements, int count)
 : InsertTester(elements, count) {} 

TesterData WorstInsertTester::test() {
    std::vector<int> input(m_elements + m_count);
    for(int i = 0; i < m_elements + m_count; i ++)
        input[i] = rand();

    TesterData data; 
    AVLTree tree; 

    for (int i = 0; i < m_elements; i ++) 
        tree.insert(input[i]);
    data.startTime = std::chrono::steady_clock::now();
    for (int i = m_elements; i < m_elements + m_count; i ++)
        tree.insert(input[i]);
    data.endTime = std::chrono::steady_clock::now();

    return data;
}
