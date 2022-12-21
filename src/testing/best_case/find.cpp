#include "find.hpp"

BestFindTester::BestFindTester(int count, AVLTree *tree) : FindTester(count, tree) {} 

TesterData BestFindTester::test() {
    TesterData data; 
    int key = m_tree->root->key;
    data.startTime = std::chrono::steady_clock::now();
    for (int i = 0; i < m_count; i ++)
        m_tree->find(key);
    data.endTime = std::chrono::steady_clock::now();
    
    return data;
}
