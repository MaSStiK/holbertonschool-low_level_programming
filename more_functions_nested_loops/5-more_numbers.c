#include "main.h"

/**
 * more_numbers - Prints digits from 0 to 9
 */
void more_numbers(void)
{
	int i;
	int l;

	for (i = 0; i < 10; i++)
	{
		for (l = 0; l < 15; l++)
		{
			if (l >= 10)
				_putchar('0' + l / 10);
			_putchar('0' + l % 10);
		}
		_putchar('\n');
	}
}
