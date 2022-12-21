#ifndef CUSTOM_TESTER
#define CUSTOM_TESTER

#include "../tester_data.hpp"
#include "../../avl_tree/avl_tree.hpp"
#include <vector>

class CustomInsertTester {
public: 
    CustomInsertTester(std::vector<int> input, AVLTree *tree = nullptr);
    TesterData test();
private:
    std::vector<int> m_input;
    AVLTree *m_tree;
};

#endif