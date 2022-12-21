#include "middle_result.hpp"

int MiddleResult::middleResult(Tester *tester, int testCount) {
    int result = 0;
    for(int i = 0; i < testCount; i ++) {
        result += tester->test().microseconds();
    }
    return result / testCount;
}