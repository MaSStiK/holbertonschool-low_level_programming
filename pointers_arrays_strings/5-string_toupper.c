#include "main.h"

/**
 * string_toupper - Converts lowercase letters to uppercase
 * @str: Pointer to the string
 *
 * Return: Pointer to str
 */
char *string_toupper(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}

	return (str);
}
