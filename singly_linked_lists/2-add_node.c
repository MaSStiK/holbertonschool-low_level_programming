#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: Pointer to the pointer to the first node
 * @str: String to duplicate
 *
 * Return: The address of the new node, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	int len = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	new->str = strdup(str);
	new->len = len;
	new->next = *head;
	*head = new;

	return (new);
}
