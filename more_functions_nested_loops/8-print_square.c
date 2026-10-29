#include "main.h"

/**
 * print_square - Prints a square using hash characters
 * @size: Size of the square
 */
void print_square(int size)
{
	int i;
	int l;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (l = 0; l < size; l++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
