#ifndef AVL_TREE
#define AVL_TREE

#include "node.hpp"

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int key);
    bool find(int key);
    void remove(int key);
    void printTree() const;

    Node *root;
private:
    friend class BestInsertTester;
    
    Node *removeRec(Node *node, int key);
    Node *findRec(Node *node, int key);
    Node *insertRec(int key, Node *node);

    Node *findMin(Node *node);
    Node *removeMin(Node *node);

    short getHeight(Node *node) const;
    short getBalanceFactor(Node *node) const;
    void recalculateHeight(Node *node);

    Node* balance(Node *node);

    Node* rotateLeft(Node *node);
    Node* rotateRight(Node *node);
};

#endif