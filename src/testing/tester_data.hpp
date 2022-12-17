#ifndef TESTER_DATA
#define TESTER_DATA

#include <chrono>

struct TesterData {
    std::chrono::_V2::steady_clock::time_point startTime;
    std::chrono::_V2::steady_clock::time_point endTime;

    int smallRotationQuantity;

    long long nanoseconds() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
    }
};

#endif