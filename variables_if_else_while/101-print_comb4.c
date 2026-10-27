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
	int j;

	for (i = 0; i < 8; i++)
	{
		for (l = i + 1; l < 9; l++)
		{
			for (j = l + 1; j < 10; j++)
			{
				putchar('0' + i);
				putchar('0' + l);
				putchar('0' + j);
				if (i != 7 || l != 8 || j != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
