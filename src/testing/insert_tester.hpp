#ifndef INSERT_TESTER
#define INSERT_TESTER

#include "tester.hpp"
#include <vector>

class InsertTester : public Tester {
public: 
    InsertTester(int count);
protected:
    int m_count;
    std::vector<int> m_input;
};

#endif