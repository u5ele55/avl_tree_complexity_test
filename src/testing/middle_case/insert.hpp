#ifndef MIDDLE_INSERT_TESTER
#define MIDDLE_INSERT_TESTER

#include "../insert_tester.hpp"

class MiddleInsertTester : public InsertTester {
public: 
    MiddleInsertTester(int count);
    TesterData test() final;
};

#endif