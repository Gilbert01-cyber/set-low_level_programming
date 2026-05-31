#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index of a listint_t list.
 * @head: A pointer to the pointer of the head of the list.
 * @index: The index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *temp;
	listint_t *next_node;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	/* Case 1: Delete the head node */
	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	/* Case 2: Traverse to the node right before the target index */
	for (i = 0; temp != NULL && i < index - 1; i++)
	{
		temp = temp->next;
	}

	/* Double check if temp or the target node itself is NULL (out of bounds) */
	if (temp == NULL || temp->next == NULL)
		return (-1);

	/* Unlink the target node and free its memory */
	next_node = temp->next->next;
	free(temp->next);
	temp->next = next_node;

	return (1);
}
