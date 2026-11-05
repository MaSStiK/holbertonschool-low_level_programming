#include "main.h"
#include <stdio.h>

/**
 * print_menu - Print the calculator menu
 */
void print_menu(void)
{
	printf("Simple Calculator\n1) Add\n2) Subtract\n");
	printf("3) Multiply\n4) Divide\n0) Quit\n"); /* Anti Betty thing */
}

/**
 * read_input - Reads user input
 * @user_input: Char array to store input
 * @text: Text to display
 */
void read_input(char *user_input, char *text)
{
	printf("%s", text);
	scanf("%s", user_input);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char user_input[11];
	char is_exit = 0;
	int a, b, result;

	print_menu();
	while (!is_exit)
	{
		read_input(user_input, "Choice: ");
		if (user_input[0] < '0' || user_input[0] > '4')
		{
			printf("Invalid choice\n");
			continue;
		}

		if (user_input[0] == '0')
		{
			printf("Bye!\n");
			is_exit = 1;
		}

		if (user_input[0] == '1')
		{
			printf("Addition\n");
			read_input(user_input, "A: ");
			a = _atoi(user_input);
			read_input(user_input, "B: ");
			b = _atoi(user_input);
			result = a + b;
			printf("Result: %d\n", result);
		}
	}

	return (0);
}
