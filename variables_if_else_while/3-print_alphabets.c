#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	size_t i;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < 26; i++)
		putchar(alphabet[i]);

	for (i = 0; i < 26; i++)
		putchar(alphabet[i] - 32);

	putchar('\n');
	return (0);
}
