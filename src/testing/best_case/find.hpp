#ifndef BEST_FIND_TESTER
#define BEST_FIND_TESTER

#include "../find_tester.hpp"

class BestFindTester : public FindTester {
public: 
    BestFindTester(int count, AVLTree *tree);
    TesterData test() final;
};

#endif