#include "main.h"

/**
 * print_triangle - Prints a right-aligned triangle
 * @size: Size of the triangle
 */
void print_triangle(int size)
{
	int i;
	int l;
	int start = size;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			start -= 1;
			for (l = 0; l < size; l++)
			{
				if (l < start)
					_putchar(' ');
				else
					_putchar('#');
			}
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
