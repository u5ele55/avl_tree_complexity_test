#include "custom_insert_tester.hpp"
#include <iostream>

CustomInsertTester::CustomInsertTester(std::vector<int> input, AVLTree *tree) 
: m_input(input), m_tree(tree) {}

TesterData CustomInsertTester::test() {
    TesterData data; 
    AVLTree *tree = m_tree ? m_tree : new AVLTree;
    
    data.startTime = std::chrono::steady_clock::now();
    for (int i : m_input) {
        tree->insert(i);
    }
    data.endTime = std::chrono::steady_clock::now();

    return data;
}