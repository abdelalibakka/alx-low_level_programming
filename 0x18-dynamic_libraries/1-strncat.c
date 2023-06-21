#include "main.h"
/**
 * _strncat - function that concatenates two strings
 * @dest: string destination
 * @src: string source
 * @n: Length of int
 * Return: returns a pointer
*/

char *_strncat(char *dest, char *src, int n)
{
	int x = 0;
	int y = 0;

	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		y++;
		x++;
	}
	return (dest);
}
