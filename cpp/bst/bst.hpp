// bst.hpp

#pragma once

struct Node {
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
};

class BST {
    public:
        BST();
        ~BST();
        int addNode(int value);
        int removeNode(int value);
        int removeRootNode();
        int peek();
        bool isEmpty();
        bool has(int value);
        void preOrderPrint();
        void inOrderPrint();
        void postOrderPrint();

    protected:
        void preOrderHelper(Node *subRoot);
        void inOrderHelper(Node *subRoot);
        void postOrderHelper(Node *subRoot);
        Node *root;
};
