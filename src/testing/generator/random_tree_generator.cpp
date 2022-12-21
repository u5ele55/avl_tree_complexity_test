#include "random_tree_generator.hpp"
#include <random>
#include <time.h>

RandomAVLTreeGenerator::RandomAVLTreeGenerator(int count) : m_count(count) {}

AVLTree* RandomAVLTreeGenerator::generate() {
    std::mt19937 generator( time(nullptr) );
    std::uniform_int_distribution< int > distribute( -2000000000, 2000000000 );
    AVLTree *tree = new AVLTree; 

    for(int i = 0; i < m_count; i ++) 
        tree->insert(distribute( generator ));
    
    return tree;
}