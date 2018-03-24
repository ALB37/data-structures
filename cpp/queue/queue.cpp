// queue.cpp

#include "queue.hpp"

void Queue::enqueue(int value) {
    appendNode(value);
}

int Queue::dequeue() {
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

int Queue::peek() {
    return LinkedList::peek();
}