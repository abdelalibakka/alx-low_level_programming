#include "hash_tables.h"

/**
 * hash_table_print - Prints the key-value pairs stored in a hash_table.
 * @ht: A pointer to the hash_table to be printed.
 *
 * return: if the hash is NULL, nothing is printed.
 *
 * Description: This function prints the key-value stored in a hash-table
 *              in the order they appear in the array of the hash_table.
 *              the format of format of the output is as follows
 *              key value, key value.
 **/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node_n;
	unsigned long int ii;
	unsigned char comman_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (ii = 0; ii < ht->size; ii++)
	{
		if (ht->array[ii] != NULL)
		{
			if (comman_flag == 1)
				printf(", ");

			node_n = ht->array[ii];
			while (node_n != NULL)
			{
				printf("'%s': '%s'", node_n->key, node_n->value);
				node_n = node_n->next;
				if (node_n != NULL)
					printf(", ");
			}
			comman_flag = 1;
		}
	}
	printf("}\n");
}
