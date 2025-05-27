#ifndef HASH_TABLE2_HPP
#define HASH_TABLE2_HPP

class HashTable2
{
private:
	struct Node
	{
		int key;
		int value;
		Node* next;
	};

	Node** table;
	int size;

public:
	HashTable2(int table_size);
	~HashTable2();
	void insert(int key, int value);
	void remove(int key);
	int hash_function(int key);
};
#endif