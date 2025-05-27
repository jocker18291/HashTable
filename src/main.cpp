#include <iostream>
#include "../include/HashTable1.hpp"
#include "../include/HashTable2.hpp"
#include "../include/HashTableAVL.hpp"

void menuHashTable1()
{
    int size;
    std::cout << "Enter size of table: ";
    std::cin >> size;
    HashTable1 ht1(size);
    int choice, key, value;

    while (true)
    {
        std::cout << "\n--- Hash Table - Open Addressing ---\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Print\n";
        std::cout << "4. Exit\n\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter key and value: ";
            std::cin >> key >> value;
            ht1.insert(key, value);
            break;
        case 2:
            std::cout << "Enter key to remove: ";
            std::cin >> key;
            ht1.remove(key);
            break;
        case 3:
            ht1.print();
            break;
        case 4:
            return;
        default:
            std::cout << "Invalid option\n";
        }
    }
}

void menuHashTable2()
{
    int size;
    std::cout << "Enter size of table: ";
    std::cin >> size;
    HashTable2 ht2(size);
    int choice, key, value;

    while (true)
    {
        std::cout << "\n--- Hash Table - Seperate Chaining ---\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Print\n";
        std::cout << "4. Exit\n\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter key and value: ";
            std::cin >> key >> value;
            ht2.insert(key, value);
            break;
        case 2:
            std::cout << "Enter key to remove: ";
            std::cin >> key;
            ht2.remove(key);
            break;
        case 3:
            ht2.print();
            break;
        case 4:
            return;
        default:
            std::cout << "Invalid option\n";
        }
    }
}

void menuHashAVL()
{
    HashAVL avl;
    int choice, key, value;

    while (true)
    {
        std::cout << "\n--- Hash Table - AVL ---\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter key and value: ";
            std::cin >> key >> value;
            avl.insert(key, value);
            break;
        case 2:
            std::cout << "Enter key to remove: ";
            std::cin >> key;
            avl.remove(key);
            break;
        case 3:
            return;
        default:
            std::cout << "Invalid option\n";
        }
    }
}

void testTableInsert()
{

}

void testTableRemove()
{

}

int main()
{
    int choice = 0;

    std::cout << "0. Use Hash Table - AVL\n";
    std::cout << "1. Use Hash Table - Open Addressing\n";
    std::cout << "2. Use Hash Table - Seperate Chaining\n";
    std::cout << "3. Test Insert on Both Tables\n";
    std::cout << "4. Test Remove on Both Tables\n";
    std::cout << "Choose implementation: ";
    std::cin >> choice;

    switch (choice)
    {
    case 0:
        menuHashAVL();
        break;
    case 1:
        menuHashTable1();
        break;
    case 2:
        menuHashTable2();
        break;
    case 3:
        testTableInsert();
        break;
    case 4:
        testTableRemove();
        break;
    default:
        std::cout << "Unknown choice, try again\n";
        break;
    }
    return 0;
}