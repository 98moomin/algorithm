#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node {
	int value;
	node* left;
	node* right;
}Node;

Node* root;

Node* insertNode(int val, Node* root) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->value = val;
		root->left = root->right = NULL;
		return root;
	}
	else {
		if (val < root->value) {
			root->left = insertNode(val, root->left);
		}
		else {
			root->right = insertNode(val, root->right);
		}
	}

	return root;
}

Node* deleteNode(int val, Node* root) {
	Node* tmp = NULL;

	if (root == NULL)
		return NULL;

	if (val < root->value) {
		root->left = deleteNode(val, root->left);
	}
	else if (val > root->value) {
		root->right = deleteNode(val, root->right);
	}
	else {
		if (root->left != NULL && root->right != NULL) {
			tmp = root->right;
			while (tmp->left != NULL)
				tmp = tmp->left;
			root->value = tmp->value;
			root->right = deleteNode(tmp->value, root->right);
		}
		else {
			tmp = (root->left == NULL) ? root->right : root->left;
			free(root);
			return tmp;
		}
	}
	return root;
}

int getHeight(Node* root) {
	int height = 0;
	if (root != NULL) {
		height = 1 + max(getHeight(root->left), getHeight(root->right));
	}
	return height;
}

int main() {
	freopen("bst.inp", "r", stdin);
	freopen("bst.out", "w", stdout);

	while (1) {
		char op; int num;
		cin >> op >> num;

		if (op == 'i' && num < 0)
			break;
		if (op == 'i')
			root = insertNode(num, root);
		else if (op == 'd')
			root = deleteNode(num, root);
	}

	cout << getHeight(root) - 1;

	return 0;
}