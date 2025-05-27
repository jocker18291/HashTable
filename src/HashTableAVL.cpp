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

int HashAVL::max(int a, int b) {
    return (a > b) ? a : b;
}

int HashAVL::getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

HashAVL::AVLNode* HashAVL::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

HashAVL::AVLNode* HashAVL::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

HashAVL::AVLNode* HashAVL::insertNode(AVLNode* node, int key, int value) {
    if(!node) return new AVLNode(key, value);

    if(key < node->key) {
        node->left = insertNode(node->left, key, value);
    } else if (key > node->key)  {
        node->right = insertNode(node->right, key, value);
    } else {
        node->value = value;
        return node;
    }
}