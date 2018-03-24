// linked-list.cpp

#include <iostream>
#include "linked-list.hpp"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}
LinkedList::~LinkedList(){
    Node *temp = head;
    while(temp != nullptr) {
        Node *next = temp->next;
        delete temp;
        temp = next;
        length--;
    }
    head = nullptr;
    tail = nullptr;
}
void LinkedList::prependNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    if (head != nullptr) {
        temp->next = head;
    } else {
        tail = temp;
    }
    head = temp;
    temp = nullptr;
    length++;
}
void LinkedList::appendNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->next = nullptr;
    if (tail != nullptr) {
        tail->next = temp;
    } else {
        head = temp;
    }
    tail = temp;
    temp = nullptr;
    length++;
}
int LinkedList::removeNode(int value) {
    if (head == nullptr) {
        return -1;
    }
    if (head->data == value) {
        if (head == tail) {
            delete tail;
            tail = nullptr;
            head = nullptr;
            length--;
            return 0;
        } else {
            Node *temp = head->next;
            delete head;
            head = temp;
            temp = nullptr;
            length--;
            return 0;
        }
    } else {
        Node *temp = head;
        while(temp != nullptr) {
            Node *next = temp->next;
            if (next->data == value) {
                if (temp->next == tail) {
                    tail = temp;
                }
                temp->next = next->next;
                delete next;
                next = nullptr;
                length--;
                return 0;
            }
            temp = next;
        }
    }
    return -1;
}
int LinkedList::peek(){
    if (head == nullptr) {
        return -1;
    } else {
        return head->data;
    }
}
bool LinkedList::isEmpty(){
    if (head == nullptr) {
        return true;
    } else {
        return false;
    }
}
bool LinkedList::has(int value){
    Node *temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
    return false;
}
int LinkedList::getLength() {
    return length;
}
void LinkedList::print(){
    Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
}
