#include "find.hpp"
#include <queue>

#include <algorithm>    // std::random_shuffle

MiddleFindTester::MiddleFindTester(int count, AVLTree* tree) : FindTester(count, tree) {} 

TesterData MiddleFindTester::test() {

    std::vector<int> input;
    std::queue<Node*> nodes;
    nodes.push(m_tree->root);

    while(!nodes.empty()) {
        Node *n = nodes.front();
        nodes.pop();
        
        if (n->left) 
            nodes.push(n->left);
        
        if (n->right) 
            nodes.push(n->right);

        input.push_back( n->key );
    }
    
    int sz = input.size();
    if (sz < m_count) {
        for(int i = sz; i < m_count; i ++)
            input.push_back(input[i % sz]);
    }
    for (int i = 0; i < m_count - 1; i++)
    {
        // generate a random number `j` such that `i <= j < n` and
        // swap the element present at index `j` with the element
        // present at current index `i`
        int j = i + rand() % (m_count - i);
        std::swap(input[i], input[j]);
    }
    TesterData data; 
    data.startTime = std::chrono::steady_clock::now();
    for (int i = 0; i < m_count; i ++)
        m_tree->find(input[i]);

    data.endTime = std::chrono::steady_clock::now();
    
    return data;
}
