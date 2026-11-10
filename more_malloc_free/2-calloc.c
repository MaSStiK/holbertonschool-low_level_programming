#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings into newly allocated memory
 * @s1: First string
 * @s2: Second string
 * @n: Maximum number of bytes to copy from s2
 *
 * Return: Pointer to the new string, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);

	if (p == NULL)
		return (NULL);

	free(p);

	return (p);
}
