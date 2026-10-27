#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	size_t l;
	char hex[] = "abcdef";

	for (i = 0; i < 10; i++)
		putchar('0' + i);

	for (l = 0; l < 6; l++)
		putchar(hex[l]);

	putchar('\n');
	return (0);
}
