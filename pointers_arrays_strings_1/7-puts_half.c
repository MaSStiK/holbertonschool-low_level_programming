#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: Pointer to the string
 */
void puts_half(char *str)
{
	int i = 0;
	int len;

	while (str[i] != '\0')
		i++;

	len = i;

	for (i = (len + 1) / 2; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}
