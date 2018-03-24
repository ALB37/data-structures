// bst.cpp

#include <iostream>
#include "bst.hpp"

using namespace std;

BST::BST(void) {
    root = NULL;
}

BST::~BST(void) {
    while (!this->removeRootNode());
}