#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sums of two matrix diagonals
 * @a: Pointer to the matrix elements
 * @size: Size of the square matrix
 */
void print_diagsums(int *a, int size)
{
	int sum = 0;
	int sum2 = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		sum += a[size * i + i];
		sum2 += a[(size * i) +  (size - 1 - i)];
	}

	printf("%d, %d\n", sum, sum2);
}
