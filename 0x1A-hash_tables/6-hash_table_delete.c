#include "hash_tables.h"

/**
 * hash_table_delete - A function that used to deletes a hash_table.
 * @ht: A pointer to a hash_table.
 *
 * Description: Write a function that deletes a hash_table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head_of = ht;
	hash_node_t *node_n, *tmp_p;
	unsigned long int ii;

	for (ii = 0; ii < ht->size; ii++)
	{
		if (ht->array[ii] != NULL)
		{
			node_n = ht->array[ii];
			while (node_n != NULL)
			{
				tmp_p = node_n->next;
				free(node_n->key);
				free(node_n->value);
				free(node_n);
				node_n = tmp_p;
			}
		}
	}
	free(head_of->array);
	free(head_of);
}
