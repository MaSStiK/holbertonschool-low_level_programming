#include "main.h"

/**
 * _strncat - Concatenates up to n characters from src to dest
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to append
 *
 * Return: Pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0' && j < n)
	{
		dest[i + j] = src[j];
		j++;
	}

	dest[i + j] = '\0';

	return (dest);
}
