#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings into newly allocated memory
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes
 *
 * Return: Pointer to the new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int i = 0;
	unsigned int size;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[i] != '\0')
		i++;

	size = i;

	p = malloc(sizeof(char) * (size + n));

	if (p == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		p[i] = s1[i];

	for (i = 0; s2[i] != '\0' && i < n; i++)
		p[i + size] = s2[i];

	return (p);
}
