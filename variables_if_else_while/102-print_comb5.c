#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	int l;

	for (i = 0; i < 99; i++)
	{
		for (l = i + 1; l < 100; l++)
		{
			putchar('0' + i / 10);
			putchar('0' + i % 10);
			putchar(' ');
			putchar('0' + l / 10);
			putchar('0' + l % 10);
			if (i != 98 || l != 99)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
