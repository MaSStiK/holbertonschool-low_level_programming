#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, 1 if an argument contains non-digit characters
 */
int main(int argc, char *argv[])
{
	int i, j;
	int result = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		result += atoi(argv[i]);
	}

	printf("%d\n", result);

	return (0);
}
