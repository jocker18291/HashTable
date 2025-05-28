#ifndef HASH_TABLE_AVL_HPP
#define HASH_TABLE_AVL_HPP

class HashAVL {
private:
    struct AVLNode {
        int key;
        int value;
        AVLNode* left;
        AVLNode* right;
        int height;

        AVLNode(int k, int v) 
            : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
    };

    void destroyTree(AVLNode* node);
    AVLNode* insertNode(AVLNode* node, int key, int value);
    AVLNode* removeNode(AVLNode* node, int key);
    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* node);
    AVLNode* rotateRight(AVLNode* node);
    int max(int a, int b);

    AVLNode** table;
    int size;
public:
    HashAVL(int size);
    ~HashAVL();
    void insert(int key, int value);
    void remove(int key);
    int hashFunction(int key);
};

#endif