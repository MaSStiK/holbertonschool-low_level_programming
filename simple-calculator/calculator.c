#include <stdio.h>

void print_menu(void);
void read_input(char *user_input, char *text);
int _atoi(char *s);
int get_number(char *input_text, char *error_text);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int option, a, b;
	int is_exit = 0;

	print_menu();
	while (!is_exit)
	{
		option = get_number("Choice:", "Invalid choice\n");

		if (option > 4 || option < 0)
		{
			printf("Invalid choice\n");
			continue;
		}

		if (option == 0)
		{
			printf("Bye!\n");
			is_exit = 1;
		}

		if (option == 1)
		{
			printf("-----\nAddition\n");
			a = get_number("A:", "Invalid number\n");
			b = get_number("B:", "Invalid number\n");
			printf("Result: %d\n-----\n", a + b);
		}

		if (option == 2)
		{
			printf("-----\nSubtraction\n");
			a = get_number("A:", "Invalid number\n");
			b = get_number("B:", "Invalid number\n");
			printf("Result: %d\n-----\n", a - b);
		}

		if (option == 3)
		{
			printf("-----\nMultiplication\n");
			a = get_number("A:", "Invalid number\n");
			b = get_number("B:", "Invalid number\n");
			printf("Result: %d\n-----\n", a * b);
		}

		if (option == 4)
		{
			printf("-----\nDivision\n");
			a = get_number("A:", "Invalid number\n");
			b = get_number("B:", "Invalid number\n");
			if (b == 0)
				printf("Error: division by zero\n-----\n");
			else
				printf("Result: %g\n-----\n", (double)a / b);
		}
	}

	return (0);
}

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
 * @text: Text to print
 */
void read_input(char *user_input, char *text)
{
	printf("%s ", text);
	scanf("%10s", user_input);
}

/**
 * _atoi - Converts a string to an integer
 * @str: String to convert
 *
 * Return: Converted integer
 */
int _atoi(char *str)
{
	int i;
	int sign = 1;
	unsigned int number = 0;
	int is_started = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			is_started = 1;
			number = number * 10 + (str[i] - '0');
		}
		else
		{
			if (is_started)
				break;
		}

		if (str[i] == '-')
			sign = -1;
	}

	return ((int)number * sign);
}

/**
 * get_number - Reads and validates a number from user input
 * @input_text: Prompt to print before reading input
 * @error_text: Error message to print for invalid input
 *
 * Return: Validated integer
 */
int get_number(char *input_text, char *error_text)
{
	char user_input[11];
	int i, number;
	int should_finish = 0;

	while (!should_finish)
	{
		should_finish = 1;

		read_input(user_input, input_text);

		for (i = 0; user_input[i] != '\0'; i++)
		{
			if ((user_input[i] < '0' || user_input[i] > '9') && user_input[i] != '-')
			{
				printf("%s", error_text);
				should_finish = 0;
				break;
			}
		}
	}

	number = _atoi(user_input);
	return (number);
}
