#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array, initialized to 0.
 * @nmemb: number of elements in the array
 * @size: size in bytes of each element
 *
 * Return: pointer to the allocated memory,
 * or NULL if nmemb/size is 0, malloc fails, or overflow occurs.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int total_size, i;

	/* Handle zero constraints */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Defensive check: Verify multiplication will not cause an overflow */
	if (nmemb > 0 && (unsigned int)-1 / nmemb < size)
		return (NULL);

	/* Calculate absolute byte footprint safely */
	total_size = nmemb * size;

	/* Allocate the raw byte container */
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	/* Initialize all allocated bytes to zero */
	for (i = 0; i < total_size; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}
