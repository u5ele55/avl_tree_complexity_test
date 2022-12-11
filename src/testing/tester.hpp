#ifndef TESTER
#define TESTER

#include "tester_data.hpp"
#include "../avl_tree/avl_tree.hpp"

class Tester {
public: 
    virtual TesterData test() = 0;
};

#endif