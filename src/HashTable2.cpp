#include "HashTable2.hpp"
#include <iostream>

HashTable2::HashTable2(int table_size)	// constructor
{
	size = table_size;
	table = new Node*[size];
	for (int i = 0; i < size; i++)
	{
		table[i] = nullptr;
	}
}

HashTable2::~HashTable2()				// desctructor
{
	for (int i = 0; i < size; i++)
	{
		Node* current = table[i];
		while (current != nullptr)
		{
			Node* delete_current = current;
			current = current->next;
			delete delete_current;
		}
	}
	delete[] table;
}

int HashTable2::hash_function(int key)
{
	return key % size;
}
