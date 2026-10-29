#include "main.h"

/**
 * print_diagonal - Prints a line of underscores
 * @n: Number of underscores to print
 */
void print_diagonal(int n)
{
	int i;
	int l;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			for (l = 0; l < i; l++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
