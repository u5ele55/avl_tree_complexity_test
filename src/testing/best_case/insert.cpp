#include "insert.hpp"
#include <queue>

#include <iostream>

BestInsertTester::BestInsertTester(int elements, int count)
 : InsertTester(elements, count) {} 


TesterData BestInsertTester::test() {
    // Generate data
    std::vector<int> input(m_elements + m_count);
    AVLTree helptree; 
    for (int i = 0; i < m_elements + m_count; i ++)
        helptree.insert(i);
    std::queue<Node*> nodes;
    nodes.push(helptree.root);
    int ind = 0;

    while(!nodes.empty()) {
        Node *n = nodes.front();
        nodes.pop();
        
        if (n->left) nodes.push(n->left);
        if (n->right) nodes.push(n->right);
        
        input[ind] = n->key;
        ind ++;
    }
    
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
