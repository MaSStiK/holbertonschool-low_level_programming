#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Difference between the first differing characters
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int difference = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			difference += s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (difference);
}
