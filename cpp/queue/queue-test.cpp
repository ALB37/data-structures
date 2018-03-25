// queue-test.cpp

#include <iostream>
#include "queue.hpp"

using namespace std;

int main() {
    Queue queue{};

    if (queue.peek() == -1 ) {
        cout << "PASS:queue initializes correctly" << endl;
    } else {
        cout << "FAIL:error in initialization" << endl;
    }

    queue.enqueue(1);

    if (queue.peek() == 1
        && queue.dequeue() == 1) {
            cout << "PASS:queue successfully enqueues and dequeues one element" << endl;
    } else {
        cout << "FAIL:error in enqueue or dequeue for one element" << endl;
    }

    queue.enqueue(1);
    queue.enqueue(2);

    if (queue.dequeue() == 1
        && queue.peek() == 2) {
            cout << "PASS:queue successfully enqueues and dequeues multiple elements" << endl;
    } else {
        cout << "FAIL:error in enqueue or dequeue for multiple elements" << endl;
    }

    return 0;
}