#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list
 * @head: Pointer to the pointer to the first node
 * @str: String to duplicate
 *
 * Return: The address of the new node, or NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	int len = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	while (*head != NULL)
		head = &(*head)->next;

	while (str[len] != '\0')
		len++;

	new->str = strdup(str);
	new->len = len;
	new->next = NULL;

	*head = new;

	return (new);
}
