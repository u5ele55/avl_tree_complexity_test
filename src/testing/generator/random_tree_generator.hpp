#ifndef RANDOM_TREE_GENERATOR
#define RANDOM_TREE_GENERATOR

#include "../../avl_tree/avl_tree.hpp"

class RandomAVLTreeGenerator {
public:
    RandomAVLTreeGenerator(int count);
    AVLTree* generate();
private:
    int m_count;
};

#endif