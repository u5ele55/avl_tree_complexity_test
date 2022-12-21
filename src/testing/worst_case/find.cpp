#include "find.hpp"
#include <queue>
#include <iostream>

WorstFindTester::WorstFindTester(int count, AVLTree *tree) : FindTester(count, tree) {} 

TesterData WorstFindTester::test() {

    std::vector<int> input(m_count);
    std::queue<Node*> nodes;
    nodes.push(m_tree->root);
    int ind = 0;

    while(!nodes.empty() && m_count > ind) {
        Node *n = nodes.front();
        nodes.pop();
        bool hasChildren = false;
        
        if (n->left) {
            nodes.push(n->left);
            hasChildren = true;
        }
        if (n->right) {
            nodes.push(n->right);
            hasChildren = true;
        }
        if (!hasChildren) {
            input[ind] = n->key;
            ind ++;
        }
    }
    
    if (ind < m_count) {
        for(int i = ind; i < m_count; i ++)
            input[i] = input[i % ind];
    }


    TesterData data; 
    data.startTime = std::chrono::steady_clock::now();
    for (int i = 0; i < m_count; i ++)
        m_tree->find(input[i]);

    data.endTime = std::chrono::steady_clock::now();
    
    return data;
}
