#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers from min to max.
 * @min: starting integer value (included)
 * @max: ending integer value (included)
 *
 * Return: pointer to the newly allocated integer array,
 * or NULL if min > max or malloc fails.
 */
int *array_range(int min, int max)
{
	int *array;
	int size, i;

	/* Rule 1: Validate range boundaries early */
	if (min > max)
		return (NULL);

	/* Calculate the element length (inclusive) */
	size = max - min + 1;

	/* Allocate exact memory block for the array of ints */
	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);

	/* Fill the array sequentially from min to max */
	for (i = 0; i < size; i++)
	{
		array[i] = min;
		min++;
	}

	return (array);
}
