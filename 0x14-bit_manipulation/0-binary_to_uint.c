#include "main.h"

Copy code
/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: a pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if the input string is invalid
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] == '0' || b[i] == '1')
		{
			result = result << 1;
			result += b[i] - '0';
			i++;
		}
		else
		{
			return (0);
		}
	}

	return (result);
	}
