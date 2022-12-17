#include "avl_tree.hpp"
#include <iostream>

AVLTree::AVLTree() : root(nullptr), smallRotations(0) {}

void AVLTree::insert(int key) {
	//std::cout << "Insert " << key << '\n';
    root = insertRec(key, root);
}

bool AVLTree::find(int key) {
    return findRec(root, key) != nullptr;
}

Node* AVLTree::insertRec(int key, Node *node) {
	if ( node == nullptr ) node = new Node(key);
	else if ( key < node->key )
		node->left = insertRec(key, node->left);
	else
		node->right = insertRec(key, node->right);
	return balance(node);
}
Node* AVLTree::findRec(Node *node, int key) const {
    if (node == nullptr) return nullptr;
    if (node->key == key) return node;

    if (node->key > key) return findRec(node->left, key);
    return findRec(node->right, key);
}

Node* AVLTree::balance(Node* node) {
	recalculateHeight(node);
	//std::cout << "BALANCE of " << node->key << " " << node->height << '\n';
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
	
	smallRotations ++;
	//std::cout << "rotateLeft " << q->key << " " << q->height << '\n';
	Node* p = q->right;
	q->right = p->left;
	p->left = q;
	recalculateHeight(q);
	recalculateHeight(p);
	return p;
}
Node* AVLTree::rotateRight(Node* p) {
	
	smallRotations ++;
	//std::cout << "rotateRight " << p->key << " " << p->height << '\n';
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