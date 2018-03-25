// bst.cpp

#include <iostream>
#include "bst.hpp"

using namespace std;

BST::BST() {
    root = NULL;
}

BST::~BST() {
    while (!this->removeRootNode());
}

int BST::addNode(int value) {
    if (this->has(value)) {
        return -1;
    }
    Node *newNode = new Node;
    newNode->data = value;
    if (this->isEmpty()) {
        root = newNode;
        return 0;
    }
    Node *currentNode = root;
    while (currentNode != nullptr) {
        if (value < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = newNode;
                return 0;
            } else {
                currentNode = currentNode->left;
            }
        } else {
            if (currentNode->right == nullptr) {
                currentNode->right = newNode;
                return 0;
            } else {
                currentNode = currentNode->right;
            }
        }
    }
}

int BST::peek() {
    if (this->isEmpty()) {
        return -1;
    } else {
        return root->data;
    }
}

bool BST::isEmpty() {
    if (root == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool BST::has(int value) {
    if (this->isEmpty()) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    Node *currentNode = root;
    while (currentNode != nullptr) {
        if (currentNode->data == value) {
            return true;
        }
        if (value < currentNode->data) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
}

void BST::preOrderPrint() {
    BST::preOrderHelper(root);
}

void BST::preOrderHelper(Node *subRoot) {
    if (subRoot == nullptr) {
        return;
    }
    cout << subRoot->data << ", ";
    BST::preOrderHelper(subRoot->left);
    BST::preOrderHelper(subRoot->right);
}

void BST::inOrderPrint() {
    BST::inOrderHelper(root);
}

void BST::inOrderHelper(Node *subRoot) {
    if (subRoot == nullptr) {
        return;
    }
    BST::inOrderHelper(subRoot->left);
    cout << subRoot->data << ", ";
    BST::inOrderHelper(subRoot->right);
}

void BST::postOrderPrint() {
    BST::postOrderHelper(root);
}

void BST::postOrderHelper(Node *subRoot) {
    if (subRoot == nullptr) {
        return;
    }
    BST::postOrderHelper(subRoot->left);
    BST::postOrderHelper(subRoot->right);
    cout << subRoot->data << ", ";
}
