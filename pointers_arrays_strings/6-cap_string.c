#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: Pointer to the string
 *
 * Return: Pointer to str
 */
char *cap_string(char *str)
{
	int i;
	int j;
	char separators[] = {' ', '\t', '\n',
		',', ';', '.', '!', '?', '"',
		'(', ')', '{', '}', '\0'};

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; separators[j] != '\0'; j++)
			if (str[i] == separators[j] && str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] -= 32;
	}

	return (str);
}
