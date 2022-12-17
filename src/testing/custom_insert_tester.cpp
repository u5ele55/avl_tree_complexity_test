#include "custom_insert_tester.hpp"
#include <iostream>

CustomInsertTester::CustomInsertTester(std::vector<int> input) : m_input(input) {}

TesterData CustomInsertTester::test() {
    TesterData data; 
    AVLTree tree; 
    data.startTime = std::chrono::steady_clock::now();
    for (int i : m_input) {
        tree.insert(i);
    }
    data.endTime = std::chrono::steady_clock::now();
    data.smallRotationQuantity = tree.smallRotations;

    return data;
}