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

#include "testing\defense\defense.hpp"


void testing() {
    std::ofstream file("some.txt", std::ios::app);
    std::srand ( unsigned ( std::time(0) ) );
    Tester *tester;

    int searchQuantity = 10000;
    int insertQuantity = 10000;
    for(int i = 20; i < 40; i ++) {
        int elementsQuantity = i * 10 * 1000;
        file << '\n';
        file << elementsQuantity << "\n";
        
        MiddleResult middle;
        tester = new BestInsertTester(elementsQuantity, insertQuantity);
        file << middle.middleResult(tester, 8) << " ";
        delete tester;
        tester = new MiddleInsertTester(elementsQuantity, insertQuantity);
        file << middle.middleResult(tester, 8) << " ";
        delete tester;
        tester = new WorstInsertTester(elementsQuantity, insertQuantity);
        file << middle.middleResult(tester, 8) << " ";
        delete tester;
        
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

        std::cout << elementsQuantity << " processed\n";
    }
    
    file.close();

}

void control() {
    AVLTree tree;
    char cmd = '\0';
    while(cmd != '0') {
        int value;
        if (cmd && cmd != '4')
            std::cin >> value;
                
        switch(cmd) {
            case '1':
                tree.insert(value);
                break;
            case '2':
                std::cout << (tree.find(value) ? "Found" : "Not found") << '\n';
                break;
            case '3':
                tree.remove(value);
                break;
            case '4':
                tree.printTree();
                break;
            default: 
                std::cout << "Please enter command from list.\n";
                break;
        }

        std::cout << "0 = Stop; 1 = Insert key; 2 = Find key; 3 = Remove key; 4 = Print tree: \n";
        std::cin >> cmd;
    }

    std::cout << "Finished.\n";
}

int main() {
    testing();
    //control();

    // Tester *tester = nullptr;
    // std::ofstream file("def.txt", std::ios::app);
    // MiddleResult middle;

    // for(int i = 205; i < 251; i += 5) {
    //     int cnt = i * 10000;

    //     RandomAVLTreeGenerator gena(cnt);
    //     AVLTree *tree = gena.generate();
    //     tester = new RandomInsertTester(tree);
        
    //     file << cnt << '\n';
    //     file << middle.middleResult(tester, 10) << "\n";

    //     delete tree;
    //     delete tester;

    //     std::cout << cnt << " processed\n"; 
    // }

    // file.close();

    return 0;
}