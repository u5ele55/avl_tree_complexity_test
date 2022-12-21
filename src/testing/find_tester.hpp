#ifndef FIND_TESTER
#define FIND_TESTER

#include "tester.hpp"
#include "../avl_tree/avl_tree.hpp"

class FindTester : public Tester {
public: 
    FindTester(int count, AVLTree *tree);
protected:
    int m_count;
    AVLTree *m_tree;
};

#endif