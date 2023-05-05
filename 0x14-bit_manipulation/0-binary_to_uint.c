#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: binary number as a string
 *
 * Return: converted number, or 0 if b is NULL or contains non-binary digits
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int len = 0;

	if (b == NULL)
		return (0);	
	while (b[len])
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		len++;
	}

	for (int i = 0; i < len; i++)
	{
		result = result << 1;
		if (b[i] == '1')
			result += 1;
	}

	return (result);
}
