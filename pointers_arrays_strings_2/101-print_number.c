#include "main.h"

/**
 * print_number - Prints an integer
 * @n: Integer to print
 */
void print_number(int n)
{
	int digit;
	int tens = 1;

	if (n < 0)
		_putchar('-');
	else
		n *= -1;

	while (n / tens <= -10)
		tens *= 10;

	while (tens > 0)
	{
		digit = (n / tens) * -1;
		_putchar(digit + '0');
		n %= tens;
		tens /= 10;
	}
}
