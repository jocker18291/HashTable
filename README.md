# HashTable

This project implements a dictionary data structure based on hash tables in C++.

## Features

- Three variants of hash tables implemented:
    - Open addressing
    - Separate chaining with linked lists
    - Hash table with AVL tree buckets

- Supports basic dictionary operations:
    - `insert(key, value)` - inserts a key-value pair
    - `remove(key)` - removes the pair associated with the key

## Project Structure

- `include/` - header files
- `src/` - source files
- `build/` - build directory (ignored by Git)
- `CMakeLists.txt` - build configuration