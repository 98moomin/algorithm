#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct Node {
	int value = -1;
	char color = 'b';
	Node* left = NULL;
	Node* right = NULL;
	Node* parent = NULL;
}Node;

Node* root, * nullNode;

Node* createNode(int val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = val;
	node->left = node->right = node->parent = NULL;

	return node;
}

Node* findNode(Node* node, int val) {
	if (node == NULL)
		return NULL;
	while (node != nullNode && val != node->value) {
		if (val < node->value)
			node = node->left;
		else
			node = node->right;
	}
	return node;
}

Node* findMin(Node* node) {
	if (node == NULL)
		return NULL;
	if (node == nullNode)
		return nullNode;
	if (node->left == nullNode)
		return node;
	return findMin(node->left);
}

void leftRotate(Node*& root, Node* x) {
	Node* y = x->right;
	x->right = y->left;
	if (y->left != nullNode)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void rightRotate(Node*& root, Node* x) {
	Node* y = x->left;
	x->left = y->right;
	if (y->right != nullNode)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}

void insertFixUp(Node*& root, Node* x) {
	while (x != root && x->parent->color == 'r') {
		if (x->parent == x->parent->parent->left) {
			Node* y = x->parent->parent->right;
			if (y->color == 'r') {
				x->parent->color = 'b';
				y->color = 'b';
				x->parent->parent->color = 'r';
				x = x->parent->parent;
			}
			else {
				if (x == x->parent->right) {
					x = x->parent;
					leftRotate(root, x);
				}
				x->parent->color = 'b';
				x->parent->parent->color = 'r';
				rightRotate(root, x->parent->parent);
			}
		}
		else {
			Node* y = x->parent->parent->left;
			if (y->color == 'r') {
				x->parent->color = 'b';
				y->color = 'b';
				x->parent->parent->color = 'r';
				x = x->parent->parent;
			}
			else {
				if (x == x->parent->left) {
					x = x->parent;
					rightRotate(root, x);
				}
				x->parent->color = 'b';
				x->parent->parent->color = 'r';
				leftRotate(root, x->parent->parent);
			}
		}
	}
	root->color = 'b';
}

void insertNode(Node*& root, Node* newNode) {
	if (root == NULL) {
		root = newNode;
		return;
	}
	if (root->value < newNode->value) {
		if (root->right == nullNode) {
			root->right = newNode;
			newNode->parent = root;
		}
		else
			insertNode(root->right, newNode);
	}
	else {
		if (root->left == nullNode) {
			root->left = newNode;
			newNode->parent = root;
		}
		else
			insertNode(root->left, newNode);
	}
}

void rbInsert(int val) {
	Node* newNode = createNode(val);
	newNode->color = 'r';
	newNode->right = newNode->left = nullNode;
	insertNode(root, newNode);
	insertFixUp(root, newNode);
}

void deleteFixUp(Node*& root, Node* x) {
	Node* w = NULL;
	while (x->parent != NULL && x->color == 'b') {
		if (x == x->parent->left) {
			w = x->parent->right;
			if (w->color == 'r') {
				w->color = 'b';
				x->parent->color = 'r';
				leftRotate(root, x->parent);
			}
			else {
				if (w->left->color == 'b' && w->right->color == 'b') {
					w->color = 'r';
					x = x->parent;
				}
				else {
					if (w->right->color == 'b') {
						w->color = 'r';
						w->left->color = 'b';
						rightRotate(root, w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = 'b';
					w->right->color = 'b';
					leftRotate(root, x->parent);
					x = root;
				}
			}
		}
		else {
			w = x->parent->left;
			if (w->color == 'r') {
				w->color = 'b';
				x->parent->color = 'r';
				rightRotate(root, x->parent);
			}
			else {
				if (w->left->color == 'b' && w->right->color == 'b') {
					w->color = 'r';
					x = x->parent;
				}
				else {
					if (w->left->color == 'b') {
						w->color = 'r';
						w->right->color = 'b';
						leftRotate(root, w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = 'b';
					w->left->color = 'b';
					rightRotate(root, x->parent);
					x = root;
				}
			}
		}
	}
	x->color = 'b';
}

void rbDelete(int val) {
	Node* x = NULL;
	Node* y = NULL;
	Node* z = findNode(root, val);

	if (z->left == nullNode || z->right == nullNode)
		y = z;
	else {
		y = findMin(z->right);
		z->value = y->value;
	}

	if (y->left != nullNode)
		x = y->left;
	else
		x = y->right;

	x->parent = y->parent;
	if (y->parent == NULL) {
		if (x == nullNode)
			root == NULL;
		else
			root = x;
	}
	else {
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}

	if (y->color == 'b')
		deleteFixUp(root, x);
}

void printColor(Node*& root, int val) {
	Node* node = findNode(root, val);
	string color = node->color == 'r' ? "RED\n" : "BLACK\n";
	cout << "color(" << node->value << "): " << color;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("rbt.inp", "r", stdin);
	freopen("rbt.out", "w", stdout);

	nullNode = (Node*)malloc(sizeof(Node));
	nullNode->color = 'b';
	nullNode->parent = nullNode->left = nullNode->right = NULL;

	while (1) {
		char op; int val;
		cin >> op >> val;
		if (op == 'i' && val == -1)
			break;

		if (op == 'i') {
			rbInsert(val);
		}
		else if (op == 'd') {
			rbDelete(val);
		}
		else if (op == 'c') {
			printColor(root, val);
		}
	}

	return 0;
}