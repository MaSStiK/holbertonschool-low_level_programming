#include <stdio.h>

int _atoi(char *s);
void print_menu(void);
void read_input(char *user_input, char *text);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char user_input[11];
	char is_exit = 0;
	int menu, a, b;

	print_menu();
	while (!is_exit)
	{
		read_input(user_input, "Choice: ");
		menu = _atoi(user_input);

		if (user_input[0] < '0' || user_input[0] > '4' || menu > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		if (menu == 0)
		{
			printf("Bye!\n");
			is_exit = 1;
		}

		if (menu == 1)
		{
			printf("Addition\n");
			read_input(user_input, "A: ");
			a = _atoi(user_input);
			read_input(user_input, "B: ");
			b = _atoi(user_input);
			printf("Result: %d\n", a + b);
		}

		if (menu == 2)
		{
			printf("Subtraction\n");
			read_input(user_input, "A: ");
			a = _atoi(user_input);
			read_input(user_input, "B: ");
			b = _atoi(user_input);
			printf("Result: %d\n", a - b);
		}

		if (menu == 3)
		{
			printf("Multiplication\n");
			read_input(user_input, "A: ");
			a = _atoi(user_input);
			read_input(user_input, "B: ");
			b = _atoi(user_input);
			printf("Result: %d\n", a * b);
		}
	}

	return (0);
}


/**
 * _atoi - Converts a string to an integer
 * @s: String to convert
 *
 * Return: Converted integer
 */
int _atoi(char *s)
{
	int i;
	int sign = 1;
	unsigned int number = 0;
	int is_started = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			is_started = 1;
			number = number * 10 + (s[i] - '0');
		}
		else
		{
			if (is_started)
				break;
		}

		if (s[i] == '-')
			sign = -1;
	}

	return ((int)number * sign);
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
 * @text: Text to display
 */
void read_input(char *user_input, char *text)
{
	printf("%s", text);
	scanf("%s", user_input);
}