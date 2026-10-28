#include "main.h"

/**
 * _abs  - Returns the absolute value of an integer
 * @n: Number to check
 *
 * Return: Absolute value of n
 */
int _abs(int n)
{
	if (n >= 0)
		return (n);

	return (n * -1);
}
