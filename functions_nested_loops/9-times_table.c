#include "main.h"

/**
 * times_table - Prints the 9 times table
 */
void times_table(void)
{
	int i;
	int l;
	int number;

	for (i = 0; i < 10; i++)
	{
		for (l = 0; l < 10; l++)
		{
			number = i * l;
			if (number < 10)
			{
				_putchar('0' + number % 10);
			}
			else
			{
				_putchar('0' + number / 10);
				_putchar('0' + number % 10);
			}

			if (l < 9)
			{
				_putchar(',');
				_putchar(' ');
				if (number < 10)
					_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
