// stack.cpp

#include "stack.hpp"

void Stack::push(int value) {
    prependNode(value);
}

int Stack::pop() {
    if (head == nullptr) {
        return -1;
    } else {
        if (head == tail) {
            int n = tail->data;
            delete tail;
            tail = nullptr;
            head = nullptr;
            length--;
            return n;
        } else {
            Node *temp = head->next;
            int n = head->data;
            delete head;
            head = temp;
            temp = nullptr;
            length--;
            return n;
        }
    }
}

int Stack::peek() {
    return LinkedList::peek();
}