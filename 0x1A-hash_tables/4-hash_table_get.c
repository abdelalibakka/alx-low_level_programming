#include "hash_tables.h"

/**
 * hash_table_get - a function that retrieves a value
 *                  associated with a key in a hash_table.
 * @ht: A pointer to the hash_table.
 * @key: A key to abtain a value, key looking for.
 * Return: If a key couldn't find - NULL.
 *         else - return tha value that associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node_n;
	unsigned long int index_i;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index_i = key_index((const unsigned char *)key, ht->size);
	if (index_i >= ht->size)
		return (NULL);

	node_n = ht->array[index_i];
	while (node_n && strcmp(node_n->key, key) != 0)
		node_n = node_n->next;

	return ((node_n == NULL) ? NULL : node_n->value);
}
