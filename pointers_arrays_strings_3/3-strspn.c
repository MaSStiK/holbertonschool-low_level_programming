#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: String to search
 * @accept: String containing accepted characters
 *
 * Return: Number of bytes in the initial segment
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;
	int is_found;

	for (i = 0; s[i] != '\0'; i++)
	{
		is_found = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				is_found = 1;
		}

		if (!is_found)
			break;
	}

	return (i);
}
