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

    AVLNode** table;
    int size;
public:
    HashAVL();
    ~HashAVL();
    void insert(int key, int value);
    void remove(int key);
    int hashFunction(int key);
};

#endif