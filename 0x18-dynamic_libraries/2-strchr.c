#include "main.h"
#include <stddef.h>
/**
 * _strchr - locates a character in a string
 * @c: first occurrence of the character
 * @s: string to be checked
 * Return: a pointer to the first occurrence of the character
 * else returns null
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			s++;
		else
			return (s);
	}
	if (c == '\0')
		return (s);

	return (NULL);
}
