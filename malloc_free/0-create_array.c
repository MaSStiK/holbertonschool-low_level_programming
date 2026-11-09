#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates an array filled with a specific character
 * @size: Number of elements in the array
 * @c: Character to fill the array with
 *
 * Return: Pointer to the array, or NULL on failure
 */
char *create_array(unsigned int size, char c)
{
	char *p;
	unsigned int i;

	if (size == 0)
		return (NULL);

	p = malloc(sizeof(char) * size);

	if (p == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = c;

	return (p);
}
