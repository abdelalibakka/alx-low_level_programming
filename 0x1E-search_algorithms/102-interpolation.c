#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements of the array
 * @value: value to search for
 * Return: 1st index where value is located or -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t l, h, pos, last_checked;

	if (array == NULL)
		return (-1);

	h = size - 1;
	l = 0;
	last_checked = -1;

	pos = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));

	last_checked = pos;

	while (l <= h && value >= array[l] && value <= array[h])
	{
		pos = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));

		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			l = pos + 1;
		else
			h = pos - 1;
	}
	printf("Value checked array[%ld] is out of range\n", last_checked);
	return (-1);
}
