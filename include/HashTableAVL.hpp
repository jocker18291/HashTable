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
    };
public:
    HashAVL();
    ~HashAVL();
    void insert(int key, int value);
    void remove(int key);
};

#endif