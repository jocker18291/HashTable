#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
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
    HashAVL avl(100003);
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

std::vector<std::pair<int, int>> generateRandom(int n) {
    std::vector<std::pair<int, int>> arr;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> key(n, (n * 5));
    std::uniform_int_distribution<> value(-500, 500);

    for (int i = 0; i < n; i++) {
        arr.push_back({ key(gen), value(gen) });
    }

    return arr;
}

int TRIALS = 100;

void testTableInsert()
{
    std::string fileName;

    std::cout << "\n --- Testing Insertion ---\n\n";
    std::cout << "Enter the file name to save results: ";
    std::cin >> fileName;
    std::ofstream MyFile(fileName);

    MyFile << "Size,HT1Time,HT2Time,AVLTime" << std::endl;

    std::vector<int> size = {1000, 10000, 50000, 100000, 250000, 500000, 750000, 1000000};

    for (int i = 0; i < 8; i++) {
        double totalH1 = 0.0, totalH2 = 0.0, totalAVL = 0.0;
        for (int j = 0; j < TRIALS; j++) {
            HashTable1 ht1(size[i] * 2);
            HashTable2 ht2(size[i] * 2);
            HashAVL avl(size[i] * 2);

            auto arr = generateRandom(size[i]);
            auto relem = generateRandom(1);

            for (auto element : arr) {
                ht1.insert(element.first, element.second);
                ht2.insert(element.first, element.second);
                avl.insert(element.first, element.second);
            }

            auto start = std::chrono::high_resolution_clock::now();
            ht1.insert(relem[0].first, relem[0].second);
            auto end = std::chrono::high_resolution_clock::now();
            totalH1 += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

            auto start2 = std::chrono::high_resolution_clock::now();
            ht2.insert(relem[0].first, relem[0].second);
            auto end2 = std::chrono::high_resolution_clock::now();
            totalH2 += std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();

            auto start3 = std::chrono::high_resolution_clock::now();
            avl.insert(relem[0].first, relem[0].second);
            auto end3 = std::chrono::high_resolution_clock::now();
            totalAVL += std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3).count();
        }
        MyFile << size[i] << "," << totalH1 / TRIALS << "," << totalH2 / TRIALS << "," << totalAVL / TRIALS << std::endl;
    }
    MyFile.close();
}

void testTableRemove()
{
    std::string fileName;

    std::cout << "\n --- Testing Insertion ---\n\n";
    std::cout << "Enter the file name to save results: ";
    std::cin >> fileName;
    std::ofstream MyFile(fileName);

    MyFile << "Size,HT1Time,HT2Time,AVLTime" << std::endl;

    std::vector<int> size = {1000, 10000, 50000, 100000, 250000, 500000, 750000, 1000000};

    for (int i = 0; i < 8; i++) {
        double totalH1 = 0.0, totalH2 = 0.0, totalAVL = 0.0;
        for (int j = 0; j < TRIALS; j++) {
            HashTable1 ht1(size[i] * 2);
            HashTable2 ht2(size[i] * 2);
            HashAVL avl(size[i] * 2);

            auto arr = generateRandom(size[i]);
            auto index = arr[rand() % arr.size()];

            for (auto element : arr) {
                ht1.insert(element.first, element.second);
                ht2.insert(element.first, element.second);
                avl.insert(element.first, element.second);
            }

            auto start = std::chrono::high_resolution_clock::now();
            ht1.remove(index.first);
            auto end = std::chrono::high_resolution_clock::now();
            totalH1 += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

            auto start2 = std::chrono::high_resolution_clock::now();
            ht2.remove(index.first);
            auto end2 = std::chrono::high_resolution_clock::now();
            totalH2 += std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();

            auto start3 = std::chrono::high_resolution_clock::now();
            avl.remove(index.first);
            auto end3 = std::chrono::high_resolution_clock::now();
            totalAVL += std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3).count();
        }
        MyFile << size[i] << "," << totalH1 / TRIALS << "," << totalH2 / TRIALS << "," << totalAVL / TRIALS << std::endl;
    }
    MyFile.close();
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