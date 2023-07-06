#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Node of Hash_table
 * @key: A size of an array
 * The key is formed a unique in the HashTable
 * @value: Value which is corresponding to a key
 * @next: A pointer to next_node of List.
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash_table of data_structure
 * @size: A size of an array
 * @array: An array of size @size
 * Each_cell of this array is a pointer to a first node of a linked_list,
 * as the HashTable uses the Chaining collision handling method
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/**
 * struct shash_node_s - adds an elements to the hash table
 * @key: A key of a string
 * A key that's unique in the Hash_Table
 * @value: A value which is corresponding to a key
 * @next: A pointer to a next_node of a List
 * @sprev: A pointer to a previous elements of a sorted linked_list
 * @snext: A pointer to a next element of a sorted linked_list
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sort hash_table data_structure
 * @size: A size of an array
 * @array: An array_of_size @size
 * Each_cell of this array is a pointer to a first_node of a linked_list,
 * as we want our Hash_Table using a Chaining collision handling method
 * @shead: A pointer to first_element of a sorted linked_list
 * @stail: A pointer to last_element of a sorted linked_list
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#endif
