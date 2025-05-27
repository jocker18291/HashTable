#ifndef HASH_TABLE_AVL_HPP
#define HASH_TABLE_AVL_HPP

class HashAVL {
private:

public:
    HashAVL();
    ~HashAVL();
    void insert(int key, int value);
    void remove(int key);
};

#endif