#include "hash_tables.h"

/**
 * key_index - function that gives the index of a key
 * @key: the hey for which we determine the index in hash table
 * @size: size of hash table's array
 * Return: index of a given key in the hash table's array
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = hash_djb2(key) % size;

	return (index);
}
