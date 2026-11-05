#include "main.h"

/**
 * _strpbrk - Searches a string for any accepted character
 * @s: String to search
 * @accept: String containing characters to search for
 *
 * Return: Pointer to the first matching character, or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i;
	int j;
	int is_found = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				is_found = 1;
				break;
			}
		}

		if (is_found)
			break;
	}

	if (!is_found)
		return ('\0');

	return (&s[i]);
}
