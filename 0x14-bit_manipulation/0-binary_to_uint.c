#include "main.h"
#include <stddef.h>

int _pow(int x, int y);
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return: converted number
 *  or 0 if b is NULL or strin B contains char other than 0 and 1
 */

unsigned int binary_to_uint(const char *b)
{
	int i, n = 0;

	unsigned int res = 0;

	if (b == NULL)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		n++;
	}
	for (i = 0; b[i]; i++)
	{
		if (b[i] == '1')
		{
			res += _pow(2, n - 1);
		}
		n--;
	}
	return (res);
}
/**
 * _pow - returns the value of x raised to power of y
 * @x: base number
 * @y: power of
 * Return: x to the power of y
 */
int _pow(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);

	return (x * _pow(x, y - 1));
}
