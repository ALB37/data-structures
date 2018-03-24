// linked-list.hpp

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void prependNode(int value);
        void appendNode(int value);
        int removeNode(int value);
        int peek();
        bool isEmpty();
        bool has(int value);
        int getLength();
        void print();

    protected:
        Node *head, *tail;
        int length;
};

#endif