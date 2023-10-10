#include "search_algos.h"

int binarySearch(int *array, int value, size_t l, size_t r);

/**
 * exponential_search -  searches for a value in a sorted array of integers
 * @array: a pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to  search for
 * Return: first index where value is located or -1 if faillure
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound, low, high;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
	{
		printf("Value checked array[%d] = [%d]\n", 0, array[0]);
		return (0);
	}

	bound = 1;
	while (bound < size && array[bound] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = (bound < size) ? bound : size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", low, high);
	return (binarySearch(array, value, low, high));
}

/**
 * binarySearch - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: pointer to the first element of the array
 * @value: value to search for
 * @l: starting index for the search
 * @r: ending index for the search
 * Return: Index where value is located, or -1 if not found
 */
int binarySearch(int *array, int value, size_t l, size_t r)
{
	size_t mid, i;

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
		else if (array[mid] < value)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return (-1);
}
