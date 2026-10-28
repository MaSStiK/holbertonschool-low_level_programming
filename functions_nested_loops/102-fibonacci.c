#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long c;
	unsigned long a = 1;
	unsigned long b = 2;

	for (i = 0; i < 50; i++)
	{
		printf("%ld", a);
		if (i < 49)
			printf(", ");

		c = a + b;
		a = b;
		b = c;
	}
	printf("\n");
	return (0);
}
