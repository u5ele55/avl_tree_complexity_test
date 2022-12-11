#ifndef NODE
#define NODE

struct Node {
    int key;
    Node *left;
    Node *right;
    short height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(0) {}
};

#endif