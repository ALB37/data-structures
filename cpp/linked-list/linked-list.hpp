// linked-list.hpp

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    public:
        LinkedList(void);
        ~LinkedList(void);
        void prependNode(int);
        void appendNode(int);
        int removeNode(int);
        int peek(void);
        bool isEmpty(void);
        bool has(int);
        int getLength(void);
        void print(void);

    private:
        Node *head, *tail;
        int length;
};

#endif