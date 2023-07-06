#include "hash_tables.h"

/**
 * hash_table_set - a function that adds an element to the hash table
 * @ht: pointer to hash table where key-value pair will be inserted
 * a struct represent hash table, contain the size of array
 * and pointer to the first node of each linked list
 * @key: the key of key-value pair
 * @value: value of key-value pair
 * Return: 1 if it succed and 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	current = ht->array[index];


	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}
	new_node = create_item((char *)key, (char *)value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
