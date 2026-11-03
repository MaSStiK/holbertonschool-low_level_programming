#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: Pointer to the string
 */
void rev_string(char *s)
{
	int i = 0;
	int len;
	char temp;

	while (s[i] != '\0')
		i++;

	len = i - 1;

	for (i = 0; i < len / 2 + 1; i++)
	{
		temp = s[i];
		s[i] = s[len - i];
		s[len - i] = temp;
	}
}
