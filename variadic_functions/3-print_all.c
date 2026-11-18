#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_char - Prints a character
 * @args: Pointer to the variable argument list
 */
void print_char(va_list *args)
{
	printf("%c", va_arg(*args, int));
}

/**
 * print_int - Prints an integer
 * @args: Pointer to the variable argument list
 */
void print_int(va_list *args)
{
	printf("%d", va_arg(*args, int));
}

/**
 * print_float - Prints a floating-point number
 * @args: Pointer to the variable argument list
 */
void print_float(va_list *args)
{
	printf("%f", va_arg(*args, double));
}

/**
 * print_str - Prints a string or (nil) if NULL
 * @args: Pointer to the variable argument list
 */
void print_str(va_list *args)
{
	char *current = va_arg(*args, char *);

	if (current == NULL)
		current = "(nil)";

	printf("%s", current);
}

/**
 * print_all - Prints arguments according to their format
 * @format: String specifying the types of arguments
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	int j = 0;
	char *separator = "";
	va_list args;

	print_funcs_t funcs[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_str},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format[i] != '\0' && format != NULL)
	{
		j = 0;

		while (funcs[j].type != '\0')
		{
			if (format[i] == funcs[j].type)
			{
				printf("%s", separator);
				funcs[j].func(&args);
				separator = ", ";
			}

			j++;
		}

		i++;
	}

	printf("\n");
	va_end(args);
}
