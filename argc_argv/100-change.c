#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * change - Calculates the number of coins for a given denomination
 * @result: Pointer to the total number of coins
 * @cents: Pointer to the remaining amount
 * @coin: Value of the coin
 */
void change(int *result, int *cents, int coin)
{
	*result += *cents / coin;
	*cents %= coin;
}

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 1 if the number of arguments is invalid
 */
int main(int argc, char *argv[])
{
	int cents;
	int result = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	change(&result, &cents, 25);
	change(&result, &cents, 10);
	change(&result, &cents, 5);
	change(&result, &cents, 2);
	change(&result, &cents, 1);
	printf("%d\n", result);

	return (0);
}
