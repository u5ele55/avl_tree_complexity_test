#include "find.hpp"

BestFindTester::BestFindTester(int count, AVLTree tree) : FindTester(count, tree) {} 

TesterData BestFindTester::test() {
    TesterData data; 
    data.startTime = std::chrono::steady_clock::now();

    for (int i = 0; i < m_count; i ++)
        m_tree.find(i / 2);

    data.endTime = std::chrono::steady_clock::now();
    return data;
}
