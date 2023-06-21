#include "main.h"
/**
 * _strcat -  function that concatenates two strings.
 * @src: string src
 * @dest: string dest
 * Return: returns char
*/

char *_strcat(char *dest, char *src)
{
	int x = 0;
	int y = 0;

	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0')
	{
		dest[x] = src[y];
		y++;
		x++;
	}
	return (dest);
}

