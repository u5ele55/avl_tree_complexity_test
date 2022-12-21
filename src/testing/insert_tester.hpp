#ifndef INSERT_TESTER
#define INSERT_TESTER

#include "tester.hpp"
#include <vector>

class InsertTester : public Tester {
public: 
    InsertTester(int elements, int insertCount);
protected:
    int m_count;
    int m_elements;
    std::vector<int> m_input;
};

#endif