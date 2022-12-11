#include "insert.hpp"
#include <queue>

#include <iostream>
#include <random>

MiddleInsertTester::MiddleInsertTester(int count) : InsertTester(count) {} 

TesterData MiddleInsertTester::test() {
    std::vector<int> input(m_count);

    std::mt19937 generator( time(nullptr) );
    std::uniform_int_distribution< uint_least32_t > distribute( 1, 6 );

    for(int i = 0; i < m_count; i ++)
        input[i] = distribute( generator );

    TesterData data; 
    AVLTree tree; 

    data.startTime = std::chrono::steady_clock::now();
    for (int i : input)
        tree.insert(i);
    data.endTime = std::chrono::steady_clock::now();
    std::cout << "MidIns " << tree.unbalancedCnt << '\n';

    return data;
}
