// queue.cpp

#include "queue.hpp"
#include "../linked-list/linked-list.cpp"

void Queue::enqueue(int value) {
    appendNode(value);
}

int Queue::dequeue() {
    if (head == NULL) {
        return -1;
    } else {
        if (head == tail) {
            int n = tail->data;
            delete tail;
            tail = NULL;
            head = NULL;
            length--;
            return n;
        } else {
            Node *temp = head->next;
            int n = head->data;
            delete head;
            head = temp;
            temp = NULL;
            length--;
            return n;
        }
    }
}