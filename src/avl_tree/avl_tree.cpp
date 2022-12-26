#include "avl_tree.hpp"
#include <iostream>
#include <queue>

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
	std::queue<Node*> nodes;
	if (root)
    	nodes.push(root);

    while(!nodes.empty()) {
        Node *n = nodes.front();
        nodes.pop();
        
        if (n->left) nodes.push(n->left);
        if (n->right) nodes.push(n->right);
        
        delete n;
    }
}

bool AVLTree::find(int key) {
    return findRec(root, key) != nullptr;
}
Node* AVLTree::findRec(Node *node, int key) {
    if (node == nullptr) return nullptr;
    if (node->key == key) return node;

    if (node->key > key) return findRec(node->left, key);
    return findRec(node->right, key);
}

void AVLTree::insert(int key) {
    root = insertRec(key, root);
}
Node* AVLTree::insertRec(int key, Node *node) {
	if ( node == nullptr ) node = new Node(key);
	else if ( key < node->key )
		node->left = insertRec(key, node->left);
	else
		node->right = insertRec(key, node->right);
	return balance(node);
}


Node* AVLTree::findMin(Node *node) {
	if (!node->left) return node;
	return findMin(node->left); 
}
Node* AVLTree::removeMin(Node* node) {
    if (!node->left) return node->right;
    node->left = removeMin(node->left);
    return balance(node);
}

Node* AVLTree::balance(Node* node) {
	recalculateHeight(node);
	if ( getBalanceFactor(node) == 2 ) {
		if ( getBalanceFactor(node->right) < 0 )
			node->right = rotateRight(node->right);
		return rotateLeft(node);
	}
	if ( getBalanceFactor(node) == -2 ) {
		if ( getBalanceFactor(node->left) > 0  )
			node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	return node; // балансировка не нужна
}

Node* AVLTree::rotateLeft(Node* q) {
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	recalculateHeight(q);
	recalculateHeight(p);
	return p;
}
Node* AVLTree::rotateRight(Node* p) {
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	recalculateHeight(p);
	recalculateHeight(q);
	return q;
}

void AVLTree::recalculateHeight(Node* node) {
	short hl = getHeight(node->left);
	short hr = getHeight(node->right);
	node->height = (hl > hr ? hl : hr) + 1;
}
short AVLTree::getHeight(Node *node) const {
    return node ? node->height : 0;
}
short AVLTree::getBalanceFactor(Node *node) const {
    return getHeight(node->right) - getHeight(node->left);
}

void AVLTree::printTree() const {
	std::queue<std::pair<Node*, short>> nodes;
	if (root)
    	nodes.push({root, 0});
	short curLevel = 0;

    while(!nodes.empty()) {
        Node *n = nodes.front().first;
		short level = nodes.front().second;
        nodes.pop();
		if (level != curLevel) {
			std::cout << "\n";
			curLevel = level;
		}
        std::cout << n->key << " ";
        if (n->left) nodes.push({n->left, level+1});
        if (n->right) nodes.push({n->right, level+1});
    }
	std::cout << '\n';
}



void AVLTree::remove(int key) {
	root = removeRec(root, key);
}
Node* AVLTree::removeRec(Node *node, int key) {
	if (!node) return nullptr;
	if (key < node->key) node->left = removeRec(node->left, key);
	else if (key > node->key) node->right = removeRec(node->right, key);
	else {
		// key found
		Node *left = node->left;
		Node *right = node->right;
		delete node;
		if (!right) return left;
		Node *minRight = findMin(right);
		minRight->right = removeMin(right);
		minRight->left = left;
		return balance(minRight);
	}

	return balance(node);
}