#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers
 * @array: pointer to the 1st element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 * Return: index where value is located
 */

int binary_search(int *array, size_t size, int value)
{
	size_t l = 0, r = size - 1, mid = 0, i;

	if (array == NULL)
		return (-1);


	while (l <= r)
	{
		mid = l + (r - l) / 2;
		printf("Searching in array: ");
		for (i = l; i < r; i++)
		{
			printf("%d, ", array[i]);
		}
		printf("%d\n", array[r]);
		if (array[mid] == value)
			return (mid);
		else if (value > array[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return (-1);
}
