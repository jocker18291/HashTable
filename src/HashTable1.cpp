#include "../include/HashTable1.hpp"
#include <iostream>

HashTable1::HashTable1(int table_size)		// constructor
{
	size = table_size;
	table = new Node[size];
	occupied = new bool[size];
	deleted = new bool[size];

	for (int i = 0; i < size; i++)
	{
		occupied[i] = false;
		deleted[i] = false;
	}
}

HashTable1::~HashTable1()					// destructor
{
	delete[] table;
	delete[] occupied;
	delete[] deleted;
}

int HashTable1::hash_function(int key)
{
	return key % size;
}

int HashTable1::search(int key, bool& found)
{
	int index = hash_function(key);
	int start_index = index;
	found = false;

	while (occupied[index] || deleted[index])
	{
		if (occupied[index] && table[index].key == key)
		{
			found = true;
			return index;
		}
		index = (index + 1) % size;
		if (index == start_index)
		{
			break;
		}
	}
	return index;
}

void HashTable1::insert(int key, int value)
{
	bool found;
	int index = search(key, found);

	if (found)
	{
		table[index].value = value;
	}
	else
	{
		table[index].key = key;
		table[index].value = value;
		occupied[index] = true;
		deleted[index] = false;
	}
}

void HashTable1::remove(int key)
{
	bool found;
	int index = search(key, found);

	if (found)
	{
		occupied[index] = false;
		deleted[index] = true;
	}
}