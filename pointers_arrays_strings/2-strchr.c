#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: String to search
 * @c: Character to locate
 *
 * Return: Pointer to the first occurrence of c, or NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			break;
	
	if (s[i] != c)
		return ('\0');

	return (&s[i]);
}
