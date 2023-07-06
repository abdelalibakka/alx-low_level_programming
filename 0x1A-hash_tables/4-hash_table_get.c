#include "hash_tables.h"

/**
 * hash_table_get - a function that retrieves a value associated with a key
 * @ht: pointer to the hash table
 * @key: the key to look for
 * Return: value associated with the key, Otherwise NULL
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			break;
		current = current->next;
	}
	if (current != NULL)
		return (current->value);
	else
		return (NULL);
}
