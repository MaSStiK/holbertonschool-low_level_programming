#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: String to convert
 *
 * Return: Converted integer
 */
int _atoi(char *s)
{
	int i;
	int sign = 1;
	unsigned int number = 0;
	int is_started = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			is_started = 1;
			number = number * 10 + (s[i] - '0');
		}
		else
		{
			if (is_started)
				break;
		}

		if (s[i] == '-')
			sign = -1;
	}

	return ((int)number * sign);
}
