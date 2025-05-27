#include "../include/HashTable2.hpp"
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

HashTable2::~HashTable2()				// destructor
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

void HashTable2::insert(int key, int value)
{
	int index = hash_function(key);
	Node* current = table[index];

	while (current != nullptr)
	{
		if (current->key == key)
		{
			current->value = value;
			return;
		}
		current = current->next;
	}

	Node* new_node = new Node;
	new_node->key = key;
	new_node->value = value;
	new_node->next = table[index];
	table[index] = new_node;
}

void HashTable2::remove(int key)
{
	int index = hash_function(key);
	Node* current = table[index];
	Node* previous_node = nullptr;

	while (current != nullptr)
	{
		if (current->key == key)
		{
			if (previous_node == nullptr)
			{
				table[index] = current->next;
			}
			else
			{
				previous_node->next = current->next;
			}
			delete current;
			return;
		}
		previous_node = current;
		current = current->next;
	}
}

void HashTable2::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "]: ";
		Node* current = table[i];
		while (current != nullptr)
		{
			std::cout << "(" << current->key << ", " << current->value << ") -> ";
			current = current->next;
		}
		std::cout << "nullptr\n";
	}
}