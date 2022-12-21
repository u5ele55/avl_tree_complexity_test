#ifndef WORST_FIND_TESTER
#define WORST_FIND_TESTER

#include "../find_tester.hpp"

class WorstFindTester : public FindTester {
public: 
    WorstFindTester(int count, AVLTree *tree);
    TesterData test() final;
};

#endif