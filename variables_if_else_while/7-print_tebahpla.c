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

	for (i = 26; i > 0; i--)
		putchar(alphabet[i - 1]);
	putchar('\n');
	return (0);
}
