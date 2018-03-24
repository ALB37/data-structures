// bst.hpp

#pragma once

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BST {
    public:
        BST();
        ~BST();
        void addNode(int value);
        int removeNode(int value);
        int removeRootNode();
        int peek();
        bool isEmpty();
        bool has(int value);
        void preOrderPrint();
        void inOrderPrint();
        void postOrderPrint();

    protected:
        Node *root;
};
