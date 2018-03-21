// stack-test.cpp

#include <iostream>
#include "stack.hpp"

using namespace std;

int main() {
    Stack *stack = new Stack;

    if (stack->peek() == -1 ) {
        cout << "PASS:stack initializes correctly" << endl;
    } else {
        cout << "FAIL:error in initialization" << endl;
    }

    stack->push(1);

    if (stack->peek() == 1
        && stack->pop() == 1) {
            cout << "PASS:stack successfully pushes and pops one element" << endl;
    } else {
        cout << "FAIL:error in push or pop for one element" << endl;
    }

    stack->push(1);
    stack->push(2);

    if (stack->pop() == 2
        && stack->peek() == 1) {
            cout << "PASS:stack successfully pushes and pops multiple elements" << endl;
    } else {
        cout << "FAIL:error in push or pop for multiple elements" << endl;
    }

    stack->~Stack();

    return 0;
}