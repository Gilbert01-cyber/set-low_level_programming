#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenates two strings up to n bytes of s2.
 * @s1: first string
 * @s2: second string to copy from
 * @n: maximum number of bytes from s2 to concatenate
 *
 * Return: pointer to the newly allocated concatenated space,
 * or NULL if memory allocation fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat_str;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Treat NULL inputs as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of strings */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* If n is greater or equal to length of s2, use entire string s2 */
	if (n >= len2)
		n = len2;

	/* Allocate space: len1 + n bytes for content + 1 byte for null-terminator */
	concat_str = malloc(sizeof(char) * (len1 + n + 1));
	if (concat_str == NULL)
		return (NULL);

	/* Copy s1 into the new memory block */
	for (i = 0; i < len1; i++)
		concat_str[i] = s1[i];

	/* Concatenate the first n bytes of s2 */
	for (j = 0; j < n; j++, i++)
		concat_str[i] = s2[j];

	/* Explicitly append the null terminator */
	concat_str[i] = '\0';

	return (concat_str);
}
