#include "main.h"

/**
 * print_alphabet_x10  - Prints the lowercase alphabet 10 times
 */
void print_alphabet_x10(void)
{
	int l;
	int i;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	for (l = 0; l < 10; l++)
	{
		for (i = 0; i < 26; i++)
			_putchar(alphabet[i]);

		_putchar('\n');
	}
}
