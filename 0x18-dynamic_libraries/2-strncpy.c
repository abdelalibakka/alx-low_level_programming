#include "main.h"
/**
 * _strncpy - function that copies a string
 * @src: string source
 * @dest: string destination
 * @n: length of int
 * Return: returns dest
*/

char *_strncpy(char *dest, char *src, int n)
{
	int x;

	for (x = 0; x < n && *(src + x); x++)
	{
		*(dest + x) = *(src + x);
	}
	for (; x < n; x++)
	{
		*(dest + x) = '\0';
	}
	return (dest);
}
