#ifndef HASH_TABLE1_HPP
#define HASH_TABLE1_HPP

class HashTable1
{
private:
	struct Node
	{
		int key;
		int value;
	};

	Node* table;
	bool* occupied;
	bool* deleted;
	int size;

public:
	HashTable1(int table_size);
	~HashTable1();
	void insert(int key, int value);
	void remove(int key);
	int hash_function(int key);
	int search(int key, bool& found);
	void print();
};

#endif
