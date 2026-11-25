#include "lists.h"

/**
 * list_len - Counts all the elements of a list_t list
 * @h: Pointer to the first node
 *
 * Return: The number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
		h = h->next;

	return (i);
}
