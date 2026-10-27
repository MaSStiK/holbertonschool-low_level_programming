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
	{
		if (alphabet[i] != "q" && alphabet[i] != "e")
			putchar(alphabet[i]);
	}
	putchar('\n');
	return (0);
}
