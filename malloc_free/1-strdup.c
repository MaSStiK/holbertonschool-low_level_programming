#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Duplicates a string into newly allocated memory
 * @str: String to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *p;
	int size;
	int i = 0;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
		i++;

	size = i;

	p = malloc(sizeof(char) * (size + 1));

	if (p == NULL)
		return (NULL);

	for (i = 0; i <= size; i++)
		p[i] = str[i];

	return (p);
}
