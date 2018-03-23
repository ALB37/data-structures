// bst.hpp

#ifndef BST_HPP
#define BST_HPP

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BST {
    public:
        BST(void);
        ~BST(void);
        void addNode(int);
        int removeNode(int);
        int peek(void);
        bool isEmpty(void);
        bool has(int);
        void preOrderPrint(void);
        void inOrderPrint(void);
        void postOrderPrint(void);

    protected:
        Node *root;
};

#endif