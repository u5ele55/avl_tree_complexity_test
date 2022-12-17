#include "testing/best_case/insert.hpp"
#include "testing/custom_insert_tester.hpp"
#include "testing/best_case/find.hpp"
#include "testing/middle_case/insert.hpp"
#include "testing/worst_case/insert.hpp"
#include <iostream>


#include <queue>

void printResult(TesterData data, std::string testname = "") {
    std::cout << testname << "\n " << data.nanoseconds() << " ns ; " << data.smallRotationQuantity << " small rotations \n";
}

int main() {
    AVLTree tree;
    int cnt = 10 * 1000000;
    std::cout << "Input size: " << cnt << '\n';
    Tester *tester;

    tester = new WorstInsertTester(cnt);
    printResult(tester->test(), "Worst Insert");
    delete tester;
    tester = new BestInsertTester(cnt);
    printResult(tester->test(), "Best Insert");
    delete tester;
    tester = new MiddleInsertTester(cnt);
    printResult(tester->test(), "Random Insert");
    delete tester;
    
    
    // std::vector<int> input(cnt);
    // AVLTree helptree; 
    // for (int i = 0; i < cnt; i ++)
    //     helptree.insert(i);
    // std::queue<Node*> nodes;
    // nodes.push(helptree.root);
    // int ind = 0;

    // while(!nodes.empty()) {
    //     Node *n = nodes.front();
    //     nodes.pop();
        
    //     if (n->left) nodes.push(n->left);
    //     if (n->right) nodes.push(n->right);
        
    //     input[ind] = n->key;
    //     ind ++;
    // }

    // CustomInsertTester tr(input);

    // printResult(tr.test(), "Custom Insert 100k");
}