#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the pointer of the head of the list.
 * @idx: The index where the new node should be added (starts at 0).
 * @n: The integer data to store in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node;
	listint_t *current;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	/* Case 1: Insert at the very beginning */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Case 2: Traverse to the node right before the target index */
	current = *head;
	for (i = 0; current != NULL && i < idx - 1; i++)
	{
		current = current->next;
	}

	/* If index is out of bounds */
	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Link the new node into the list */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
