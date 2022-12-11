#ifndef BEST_INSERT_TESTER
#define BEST_INSERT_TESTER

#include "../insert_tester.hpp"

class BestInsertTester : public InsertTester {
public: 
    BestInsertTester(int count);
    TesterData test() final;
};

#endif