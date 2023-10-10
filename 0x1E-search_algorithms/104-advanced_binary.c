#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 * Return: The index where the value is located or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i;
    int middle;

    if (array == NULL)
        return (-1);

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");

    if (size == 1 && array[0] != value)
        return (-1);

    middle = (size - 1) / 2;

    if (array[middle] == value)
    {
        if (middle > 0 && array[middle - 1] == value)
            return advanced_binary(array, middle + 1, value);
        return (middle);
    }

    if (array[middle] < value)
    {
        return advanced_binary(array + middle + 1, size - middle - 1, value) + middle + 1;
    }
    return advanced_binary(array, middle, value);
}
