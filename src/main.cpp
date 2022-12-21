#include "testing/best_case/insert.hpp"
#include "testing/custom/custom_insert_tester.hpp"
#include "testing/best_case/find.hpp"
#include "testing/middle_case/insert.hpp"
#include "testing/worst_case/insert.hpp"
#include "testing/worst_case/find.hpp"
#include "testing/middle_case/find.hpp"

#include "testing/generator/random_tree_generator.hpp"
#include "testing/utilities/middle_result.hpp"
#include <iostream>
#include <fstream>

#include <queue>



void testing() {
    std::ofstream file("some.txt", std::ios::app);
    std::srand ( unsigned ( std::time(0) ) );
    Tester *tester;

    int searchQuantity = 10000;
    int insertQuantity = 10000;
    for(int i = 20; i < 21; i ++) {
        // int elementsQuantity = i * 100 * 1000;
        // file << '\n';
        // file << elementsQuantity << "\n";
        
        // MiddleResult middle;
        // tester = new BestInsertTester(elementsQuantity, insertQuantity);
        // file << middle.middleResult(tester, 8) << " ";
        // delete tester;
        // tester = new MiddleInsertTester(elementsQuantity, insertQuantity);
        // file << middle.middleResult(tester, 8) << " ";
        // delete tester;
        // tester = new WorstInsertTester(elementsQuantity, insertQuantity);
        // file << middle.middleResult(tester, 8) << " ";
        // delete tester;
        
        // RandomAVLTreeGenerator gena(elementsQuantity);
        // AVLTree *tree = gena.generate();

        // tester = new BestFindTester(searchQuantity, tree);
        // file << middle.middleResult(tester, 10) << " ";
        // delete tester;
        // tester = new MiddleFindTester(searchQuantity, tree);
        // file << middle.middleResult(tester, 10) << " ";
        // delete tester;
        // tester = new WorstFindTester(searchQuantity, tree);
        // file << middle.middleResult(tester, 10) << " ";
        // delete tester;
        // delete tree;

        // std::cout << elementsQuantity << " processed\n";
    }
    
    file.close();

}

int main() {
    //testing();

    return 0;
}