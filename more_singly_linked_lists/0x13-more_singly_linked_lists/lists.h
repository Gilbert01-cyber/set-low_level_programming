#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for ALX project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/* Counter-attack function prototypes will be placed right below here */

#endif
