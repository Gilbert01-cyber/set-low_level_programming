#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - function executed before main
 *
 * Description: Prints a message from the tortoise before the main
 * function begins execution.
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
