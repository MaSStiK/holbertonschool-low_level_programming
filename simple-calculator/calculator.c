#include <stdio.h>

void print_menu()
{
	printf("Simple Calculator\n1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
}

void read_input(char *user_input, char *text)
{
	printf("%s", text);
	scanf("%s", user_input);
}

int main(void)
{
	char user_input[100];
	char is_exit = 0;

	print_menu();
	while (!is_exit)
	{
		read_input(user_input, "Choice: ");

		if (user_input[0] == '0')
		{
			printf("Quit\n");
			is_exit = 1;
		}
	}

	return (0);
}
