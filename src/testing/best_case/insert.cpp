#include "insert.hpp"
#include <queue>

#include <iostream>

BestInsertTester::BestInsertTester(int count) : InsertTester(count) {} 

TesterData BestInsertTester::test() {
    // Generate data
    std::vector<int> input(m_count);
    AVLTree helptree; 
    for (int i = 0; i < m_count; i ++)
        helptree.insert(i);
    std::queue<Node*> nodes;
    nodes.push(helptree.root);
    int ind = 0;

    while(!nodes.empty()) {
        Node *n = nodes.front();
        nodes.pop();
        //std::cout << n->key << " ";
        if (n->left) nodes.push(n->left);
        if (n->right) nodes.push(n->right);
        
        input[ind] = n->key;
        ind ++;
    }
    
    TesterData data; 
    AVLTree tree;
    
    data.startTime = std::chrono::steady_clock::now();
    for (int i : input)
        tree.insert(i);
    data.endTime = std::chrono::steady_clock::now();
    
    std::cout << "BestIns " << tree.unbalancedCnt << '\n';
    return data;
}
