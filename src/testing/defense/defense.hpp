#ifndef DEFENSE_TESTER
#define DEFENSE_TESTER

#include "../insert_tester.hpp"
#include "../../avl_tree/avl_tree.hpp"
#include <vector>

class RandomInsertTester : public InsertTester {
public: 
    RandomInsertTester(AVLTree *tree = nullptr);
    TesterData test();
private:
    AVLTree *m_tree;
};

#endif