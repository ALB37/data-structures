// linked-list.hpp

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Node
{
    public:
        Node(const int);
        const int* getData() const;
        void setData(const int);
        ~Node(void);

    private:
        Node* next;
        int data;
};

class LinkedList
{
    public:
        LinkedList(void);
        ~LinkedList(void);

    private:
        Node head;
};

#endif