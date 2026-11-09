#include <stdlib.h>
#include "main.h"

/**
 * str_concat - Concatenates two strings into newly allocated memory
 * @s1: First string
 * @s2: Second string
 *
 * Return: Pointer to the new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	int i = 0;
	int size_s1, size_s2;

	if (s1 == NULL)
	s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[i] != '\0')
		i++;

	size_s1 = i;
	i = 0;

	while (s2[i] != '\0')
		i++;

	size_s2 = i;

	p = malloc(sizeof(char) * (size_s1 + size_s2 + 1));

	if (p == NULL)
		return (NULL);

	for (i = 0; i < size_s1; i++)
		p[i] = s1[i];

	for (i = 0; i < size_s2; i++)
		p[size_s1 + i] = s2[i];

	p[size_s1 + size_s2] = '\0';

	return (p);
}
