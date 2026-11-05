#include <stdio.h>

void print_menu(void)
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

		switch (user_input[0])
		{
			case '0':
				printf("Bye!\n");
				is_exit = 1;
				break;

			case '1':
				printf("1 add\n");
				break;

			default:
				printf("Invalid choice\n");
				break;
		}
	}

	return (0);
}
