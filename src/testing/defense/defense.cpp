#include "defense.hpp"
#include <iostream>

RandomInsertTester::RandomInsertTester(AVLTree *tree) : m_tree(tree), InsertTester(0, 50) {}

TesterData RandomInsertTester::test() {
    TesterData data; 
    
    data.startTime = std::chrono::steady_clock::now();
    for(int i = 0; i < m_count; i ++)
        m_tree->insert(std::rand());
    data.endTime = std::chrono::steady_clock::now();

    return data;
}