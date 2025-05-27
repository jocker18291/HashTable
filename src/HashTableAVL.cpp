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
    if(node == nullptr) return;
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

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if(balance > 1 && key < node->left->key)
        return rotateRight(node);
    
    if(balance < -1 && key > node->right->key)
        return rotateLeft(node);

    if(balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if(balance < -1 && key < node->right->key) {
        node->right = rotateRight(node);
        return rotateLeft(node);
    }

    return node;
}

void HashAVL::insert(int key, int value) {
    int index = hashFunction(key);
    table[index] = insertNode(table[index], key, value);
}

HashAVL::AVLNode* HashAVL::removeNode(AVLNode* node, int key) {
    if (!node) return nullptr;

    if(key < node->key) {
        node->left = removeNode(node->left, key);
    } else if (key > node->key) {
        node->right = removeNode(node->right, key);
    }
    else {
        if(!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        } else {
            AVLNode* temp = node->right;
            while(temp->left)
                temp=temp->left;
            
            node->key = temp->key;
            node->value = temp->value;
            node->right = removeNode(node->right, temp->key);
        }
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if(balance > 1 && getBalance(node->left) >= 0) {
        return rotateRight(node);
    }

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void HashAVL::remove(int key) {
    int index = hashFunction(key);
    table[index] = removeNode(table[index], key);
}