#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data (n) of a listint_t list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The total sum of all the data (n). If the list is empty, return 0.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
