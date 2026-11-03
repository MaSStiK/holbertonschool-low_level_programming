#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: Pointer to the string
 */
void rev_string(char *s)
{
	int i;
	int len;
	char copy[10];

	for (i = 0; s[i] != '\0'; i++)
		copy[i] = s[i];

	len = i - 1;
	for (i = 0; i <= len; i++)
		s[i] = copy[len - i];
}
