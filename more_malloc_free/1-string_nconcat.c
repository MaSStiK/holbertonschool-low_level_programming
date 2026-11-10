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
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int i;
	unsigned int size_s1 = 0;
	unsigned int size_s2 = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[size_s1] != '\0')
		size_s1++;

	while (s2[size_s2] != '\0')
		size_s2++;

	if (size_s2 > n)
		size_s2 = n;

	p = malloc(sizeof(char) * (size_s1 + size_s2 + 1));

	if (p == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		p[i] = s1[i];

	for (i = 0; s2[i] != '\0' && i < size_s2; i++)
		p[i + size_s1] = s2[i];

	p[i + size_s1] = '\0';

	return (p);
}
