#include "testing/best_case/insert.hpp"
#include "testing/best_case/find.hpp"
#include "testing/middle_case/insert.hpp"
#include "testing/worst_case/insert.hpp"
#include <iostream>

void printResult(TesterData data, std::string testname = "") {
    std::cout << testname << " " << data.nanoseconds() << " ns\n";
}

int main() {
    AVLTree tree;

    Tester *tester;

    tester = new WorstInsertTester(1000000);
    printResult(tester->test(), "Worst Insert 100k");

    tester = new MiddleInsertTester(1000000);
    printResult(tester->test(), "Middle Insert 100k");

    tester = new BestInsertTester(1000000);
    printResult(tester->test(), "Best Insert 100k");
}