// program.cpp

#include <iostream>
#include "linked-list.hpp"

using namespace std;

int main() {
    LinkedList *list = new LinkedList;

    if (list->getLength() == 0
        && list->peek() == -1
        && list->isEmpty() == 1) {
            cout << "PASS:linked list initializes correctly" << endl;
        
    } else {
        cout << "FAIL:error in initialization" << endl;
    }

    list->appendNode(1);

    if (list->peek() == 1
        && list->getLength() == 1) {
            cout << "PASS:linked list appends first node correctly" << endl;
    } else {
        cout << "FAIL:error in first append" << endl;
    }

    list->appendNode(2);
    list->appendNode(3);

    if (list->peek() == 1
        && list->getLength() == 3
        && list->isEmpty() == 0) {
            cout << "PASS:additional nodes appended successfully" << endl;
    } else {
        cout << "FAIL:error in appending additional nodes" << endl;
    }

    list->removeNode(1);

    if (list->peek() == 2
        && list->getLength() == 2) {
            cout << "PASS:remove node from beginning of linked list successful" << endl;
    } else {
        cout << "FAIL:error in removing node from front of linked list" << endl;
    }

    list-> removeNode(3);

    if (list->peek() == 2
        && list->getLength() == 1) {
            cout << "PASS:remove node from end of linked list successful" << endl;
    } else {
        cout << "FAIL:error in removing node from end of linked list" << endl;
    }

    list->removeNode(2);

    if (list->peek() == -1
        && list->getLength() == 0
        && list->isEmpty() == 1) {
            cout << "PASS:removing only node successful" << endl;
    } else {
        cout << "FAIL:error in removing only node from linked list" << endl;
    }

    if (list->removeNode(2) == -1) {
        cout << "PASS:remove returns correct value when nothing to remove" << endl;
    } else {
        cout << "FAIL:remove returns incorrect value when removing nothing" << endl;
    }

    list->prependNode(5);

    if (list->getLength() == 1
        && list->peek() == 5
        && list->isEmpty() == 0) {
            cout << "PASS:prepend on empty list successful" << endl;
    } else {
        cout << "FAIL:error in prepend on empty list" << endl;
    }

    list->prependNode(4);
    list->prependNode(3);
    list->prependNode(2);
    list->prependNode(1);

    if (list->getLength() == 5
        && list->peek() == 1) {
            cout << "PASS:prepend on list with values successful" << endl;
    } else {
        cout << "FAIL:error in prepend on list with values" << endl;
    }

    if (list->has(1) == 1
        && list->has(2) == 1
        && list->has(5) == 1) {
            cout << "PASS:has method correctly returns true on existing values" << endl;
    } else {
        cout << "FAIL:error on has method with existing values" << endl;
    }

    if (list->has(6) == 0) {
        cout << "PASS:has method correctly returns false on values not in list" << endl;
    } else {
        cout << "FAIL:error in has method on non-existing list values" << endl;
    }

    cout << "Next test passes if it prints out 1, 2, 3, 4 and 5 on separate lines" << endl;

    list->print();

    list->~LinkedList();
    
    return 0;
}
