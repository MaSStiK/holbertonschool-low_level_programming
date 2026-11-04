#include "main.h"

/**
 * _strncat - Concatenates up to n characters from src to dest
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to append
 *
 * Return: Pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	int len = 0;

	while (dest[i] != '\0')
		i++;

	len = i;
	i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	dest[len] = '\0';

	return (dest);
}
