#include <stdio.h>
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	for (i = 0; i < strlen(alphabet); i++)
		putchar(alphabet[i]);
	putchar("\n");
	return (0);
}
