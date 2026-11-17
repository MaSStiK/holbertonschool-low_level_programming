#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "3-calc.h"

 /**
 * main - Entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int (*op_func)(int, int);
	int a, b, result;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	op = argv[2];
	b = atoi(argv[3]);

	op_func = get_op_func(op);

	if (op_func == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((op[0] == '/' || op[0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = op_func(a, b);
	printf("%d\n", result);

	return (0);
}
