// linked-list.cpp

#include <iostream>
#include "linked-list.hpp"

using namespace std;

LinkedList::LinkedList(void) {
    head = NULL;
    tail = NULL;
    length = 0;
}
LinkedList::~LinkedList(void){
    Node *temp = head;
    while(temp != NULL) {
        Node *next = temp->next;
        delete temp;
        temp = next;
        length--;
    }
    head = NULL;
    tail = NULL;
}
void LinkedList::prependNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if (head != NULL) {
        temp->next = head;
    } else {
        tail = temp;
    }
    head = temp;
    temp = NULL;
    length++;
}
void LinkedList::appendNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if (tail != NULL) {
        tail->next = temp;
    } else {
        head = temp;
    }
    tail = temp;
    temp = NULL;
    length++;
}
int LinkedList::removeNode(int value) {
    if (head == NULL) {
        return -1;
    }
    if (head->data == value) {
        if (head == tail) {
            delete tail;
            tail = NULL;
            head = NULL;
            length--;
            return 0;
        } else {
            Node *temp = head->next;
            delete head;
            head = temp;
            temp = NULL;
            length--;
            return 0;
        }
    } else {
        Node *temp = head;
        while(temp != NULL) {
            Node *next = temp->next;
            if (next->data == value) {
                if (temp->next == tail) {
                    tail = temp;
                }
                temp->next = next->next;
                delete next;
                next = NULL;
                length--;
                return 0;
            }
            temp = next;
        }
    }
    return -1;
}
int LinkedList::peek(void){
    if (head == NULL) {
        return -1;
    } else {
        return head->data;
    }
}
bool LinkedList::isEmpty(void){
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}
bool LinkedList::has(int value){
    Node *temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
    return false;
}
int LinkedList::getLength(void) {
    return length;
}
void LinkedList::print(void){
    Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
}
