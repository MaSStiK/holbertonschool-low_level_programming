#include "main.h"

/**
 * _strstr - Locates a substring in a string
 * @haystack: String to search
 * @needle: Substring to locate
 *
 * Return: Pointer to the first occurrence, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;
	int is_found = 0;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != '\0' && haystack[i + j] == needle[j])
			{
				is_found = 1;
			}
			else
			{
				is_found = 0;
				break;
			}
		}

		if (is_found)
			break;
	}

	if (!is_found)
		return ('\0');

	return (&haystack[i]);
}
