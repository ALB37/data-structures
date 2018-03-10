// linked-list.hpp

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

struct Node
{
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