#ifndef MIDDLE_FIND_TESTER
#define MIDDLE_FIND_TESTER

#include "../find_tester.hpp"

class MiddleFindTester : public FindTester {
public: 
    MiddleFindTester(int count, AVLTree *tree);
    TesterData test() final;
};

#endif