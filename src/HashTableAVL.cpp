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