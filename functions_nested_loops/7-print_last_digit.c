#include "main.h"

/**
 * print_last_digit  - Prints the last digit of a number
 * @n: Number to check
 *
 * Return: Value of the last digit
 */
int print_last_digit(int n)
{
	int digit = n % 10;

	if (n < 0)
		digit = digit * -1;

	_putchar('0' + digit);
	return (digit);
}
