#pragma once

#include <string>
#include <iostream>
using namespace std;

class EmployeeInfo {

public:

	int employeeId;
	string employeeName;
};

struct node {

	EmployeeInfo info;
	node* left;
	node* right;
};

class binaryTree {
public:
	binaryTree();
	~binaryTree();
	void insert(EmployeeInfo key);
	node* search(int key);
	void destroy_tree();

private:
	void destroy_tree(node* leaf);
	void insert(EmployeeInfo key, node* leaf);
	node* search(int key, node* leaf);
	node* root;
};

binaryTree::binaryTree() {
	root = NULL;
}

void binaryTree::destroy_tree(node* leaf) {

	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void binaryTree::insert(EmployeeInfo key, node* leaf) {

	if (key.employeeId < leaf->info.employeeId) {
		if (leaf->left != NULL) {

			insert(key, leaf->left);

		}else {
			leaf->left = new node;
			leaf->left->info = key;
			leaf->left->left = NULL; //Sets the left child null
			leaf->left->right = NULL; //Sets the right child null
		}
	}else if (key.employeeId >= leaf->info.employeeId) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}else {
			leaf->right = new node;
			leaf->right->info = key;
			leaf->right->left = NULL; //Sets the left child  to null
			leaf->right->right = NULL; //Sets the right child to null
		}
	}
}

node* binaryTree::search(int key, node* leaf) {
	if (leaf != NULL) {
		if (key == leaf->info.employeeId) {
			return leaf;
		}

		if (key < leaf->info.employeeId) {
			return search(key, leaf->left);
		}else {
			return search(key, leaf->right);
		}
	}else {
		return NULL;
	}
}

node* binaryTree::search(int key) {
	return search(key, root);
}

void binaryTree::destroy_tree() {
	destroy_tree(root);
}

void binaryTree::insert(EmployeeInfo key) {
	if (root != NULL) {
		insert(key, root);
	}else {
		root = new node;
		root->info = key;
		root->left = NULL;
		root->right = NULL;
	}
}