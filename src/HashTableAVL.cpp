#include "../include/HashTableAVL.hpp"
#include <iostream>
#include <cstdlib>

HashAVL::HashAVL() {
    size = 100003;
    table = new AVLNode*[size];
    for(int i = 0; i < size; i++) {
        table[i] = nullptr;
    }
}

void HashAVL::destroyTree(AVLNode* node) {
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

HashAVL::~HashAVL() {
    for(int i = 0; i < size; i++) {
        destroyTree(table[i]);
    }
    delete[] table;
}

int HashAVL::hashFunction(int key) {
    if(key < 0) key = -key;

    return key % size;
}

int HashAVL::getHeight(AVLNode* node) {
    return node ? node->height : 0;
}