#include "main.h"

/**
 * jack_bauer - Prints every minute of the day
 */
void jack_bauer(void)
{
	int i;
	int l;

	for (i = 0; i < 24; i++)
	{
		for (l = 0; l < 60; l++)
		{
			_putchar('0' + i / 10);
			_putchar('0' + i % 10);
			_putchar(':');
			_putchar('0' + l / 10);
			_putchar('0' + l % 10);
			_putchar('\n');
		}
	}
}
