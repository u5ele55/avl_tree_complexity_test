#ifndef WORST_INSERT_TESTER
#define WORST_INSERT_TESTER

#include "../insert_tester.hpp"

class WorstInsertTester : public InsertTester {
public: 
    WorstInsertTester(int count);
    TesterData test() final;
};

#endif