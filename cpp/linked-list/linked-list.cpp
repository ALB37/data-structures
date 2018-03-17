// linked-list.cpp

#include <iostream>
#include "linked-list.hpp"

class LinkedList {
    public:
        LinkedList(void) {
            Node *head = NULL;
            Node *tail = NULL;
            int length = 0;
        }
        ~LinkedList(void){
            Node *temp = head;
            while(temp != NULL) {
                Node *next = temp->next;
                delete temp;
                temp = next;
                length--;
            }
            head = NULL;
        }
        void prependNode(int value) {
            Node *temp = new Node;
            temp->data = value;
            if (head != NULL) {
                temp->next = head;
            } else {
                tail = temp;
            }
            head = temp;
            length++;
        }
        void appendNode(int value) {
            Node *temp = new Node;
            temp->data = value;
            if (tail != NULL) {
                tail->next = temp;
            } else {
                head = temp;
            }
            tail = temp;
            length++;
        }
        int removeNode(int value) {
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
                    length--;
                    return 0;
                }
            } else {
                Node *temp = head;
                while(temp != NULL) {
                    // still need to account for condition
                    // where tail is the value to be removed
                    Node *next = temp->next;
                    if (next->data == value) {
                        temp->next = next->next;
                        delete next;
                        length--;
                        return 0;
                    }
                    temp = next;
                }
            }
            return -1;
        }
        int peek(void){
            if (head == NULL) {
                return -1;
            } else {
                return head->data;
            }
        }
        bool isEmpty(void){
            if (head == NULL) {
                return true;
            } else {
                return false;
            }
        }
        bool has(int value){
            Node *temp = head;
                while (temp != NULL) {
                    if (temp->data == value) {
                        return true;
                    }
                    temp = temp->next;
                }
            return false;
        }
        int getLength(void) {
            return length;
        }
        void print(void){
            Node *temp = head;
                while (temp != NULL) {
                    std::cout << temp->data << std::endl;
                    temp = temp->next;
                }
        }
    private:
        Node *head, *tail;
        int length = 0;
};

        
        