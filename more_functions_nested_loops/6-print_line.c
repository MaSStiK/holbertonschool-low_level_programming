#include "main.h"

/**
 * print_line - Prints a line of underscores
 * @n: Number of underscores to print
 */
void print_line(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
			_putchar('_');
	}
	_putchar('\n');
}
