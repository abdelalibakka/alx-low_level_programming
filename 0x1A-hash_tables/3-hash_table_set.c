#include "hash_tables.h"

/**
 * hash_table_set - Add an element in a hash_table.
 * @ht: A pointer to the hash_table.
 * @key: The key to adding - can't be an empty _tring.
 * @value: An associated a vlaue  with a key.
 *
 * Return: when failure - 0.
 *         else - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_n;
	char *val_copy;
	unsigned long int index_i, ii;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);

	index_i = key_index((const unsigned char *)key, ht->size);
	for (ii = index_i; ht->array[ii]; ii++)
	{
		if (strcmp(ht->array[ii]->key, key) == 0)
		{
			free(ht->array[ii]->value);
			ht->array[ii]->value = val_copy;
			return (1);
		}
	}

	new_n = malloc(sizeof(hash_node_t));
	if (new_n == NULL)
	{
		free(val_copy);
		return (0);
	}
	new_n->key = strdup(key);
	if (new_n->key == NULL)
	{
		free(new_n);
		return (0);
	}
	new_n->value = val_copy;
	new_n->next = ht->array[index_i];
	ht->array[index_i] = new_n;

	return (1);
}
