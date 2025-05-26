cmake_minimum_required(VERSION 3.10)
project(HashTable)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(hash_table_exec
    src/main.cpp
    src/HashTable1.cpp
    src/HashTable2.cpp
    src/HashTableAVL.cpp
)
