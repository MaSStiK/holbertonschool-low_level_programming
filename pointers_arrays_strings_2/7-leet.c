#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: Pointer to the string
 *
 * Return: Pointer to str
 */
char *leet(char *str)
{
	int i;
	int j;
	char rules[] = "aA4eE3oO0tT7lL1";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; rules[j] != '\0'; j += 3)
			if (str[i] == rules[j] || str[i] == rules[j + 1])
				str[i] = rules[j + 2];
	}

	return (str);
}
