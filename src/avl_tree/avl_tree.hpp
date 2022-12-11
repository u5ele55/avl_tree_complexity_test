#ifndef AVL_TREE
#define AVL_TREE

#include "node.hpp"

class AVLTree {
public:
    AVLTree();

    void insert(int key);
    bool find(int key);

    int unbalancedCnt;
private:
    friend class BestInsertTester;
    Node *root;

    Node *findRec(Node *node, int key) const;
    Node *insertRec(int key, Node *node);

    short getHeight(Node *node) const;
    short getBalanceFactor(Node *node) const;
    void recalculateHeight(Node *node);

    Node* balance(Node *node);

    Node* rotateLeft(Node *node);
    Node* rotateRight(Node *node);
};

#endif