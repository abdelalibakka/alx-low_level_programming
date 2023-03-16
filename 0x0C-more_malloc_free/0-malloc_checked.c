#include<stdlib.h>
/**
 * malloc_checked - function contrat any type of varible and
 * use function exit if we have an error in allocation
 *
 * @b: prisent the size of the variable give them in argument
 *
 * Return: return variable pointer type void or exit befor if we have a problem
 */
void *malloc_checked(unsigned int b)
{
	void *i;

	i = malloc(b);
	if (i == NULL)
		exit(98);
	return (i);
}
