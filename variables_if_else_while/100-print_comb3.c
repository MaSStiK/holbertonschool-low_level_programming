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

	for (i = 0; i < 9; i++)
	{
		for (l = i + 1; l < 10; l++)
		{
			putchar('0' + i);
			putchar('0' + l);
			if (i != 8 || l != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
