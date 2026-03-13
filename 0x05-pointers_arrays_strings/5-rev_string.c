#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: string to reverse
 */
void rev_string(char *s)
{
int i = 0;
int j = 0;
char tmp;

/* Find the end of the string */
while (s[j] != '\0')
{
j++;
}
j--; /* Move back from the null terminator to the last char */

/* Swap characters from outside in */
while (i < j)
{
tmp = s[i];
s[i] = s[j];
s[j] = tmp;
i++;
j--;
}
}
