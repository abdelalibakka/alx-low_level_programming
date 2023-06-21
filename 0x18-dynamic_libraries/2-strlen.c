#include "main.h"
/**
 * _strlen - return the length of a string
 * @s: char to check
 * Return: returns length of the length
*/

int _strlen(char *s)
{
	int len = 0;

	for (; *s++;)
	{
		len++;
	}
	return (len);
}
