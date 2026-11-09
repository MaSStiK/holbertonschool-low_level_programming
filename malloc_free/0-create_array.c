#include <stdlib.h>
#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 * @s: Pointer to the memory area
 * @b: Byte to fill the memory with
 * @n: Number of bytes to fill
 *
 * Return: Pointer to s
 */
char *create_array(unsigned int size, char c)
{
	char *p;
	unsigned int i;

	if (size == 0)
		return ('\0');

	p = (char *)malloc(sizeof(char) * size);

	for (i = 0; i < size; i++)
		p[i] = c;

	return (p);
}
