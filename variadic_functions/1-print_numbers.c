#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers separated by a string
 * @separator: String to print between numbers
 * @n: Number of integers to print
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));

		if (i != n - 1 && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}
