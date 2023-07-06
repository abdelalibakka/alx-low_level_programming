#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table
 * @size: size of the array
 * Return: the new hash table created
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;
	unsigned long int i;

	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = malloc(sizeof(hash_node_t *) * size);
	if (table->array == NULL)
		return (NULL);

	for (i = 0; i < table->size; i++)
	{
		table->array[i] = NULL;
	}
	return (table);
}

/**
 * create_item - create a new item in the array
 * @key: position at the array
 * @value: the value assigned at a specific position
 * Return: new element in the array of linked list
 */
hash_node_t *create_item(char *key, char *value)
{
	hash_node_t *item;

	item = malloc(sizeof(hash_node_t));
	if (item == NULL)
		return (NULL);

	item->key = malloc(strlen(key) + 1);
	item->value = malloc(strlen(value) + 1);
	strcpy(item->key, key);
	strcpy(item->value, value);

	return (item);
}
