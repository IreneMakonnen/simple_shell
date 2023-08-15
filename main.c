#include "shell.h"

/**
 * main - Entry point of program
 * Return: Always 0 (Success)
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARGS];

	while (1)
	{
		printf("simple_shell> ");
		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strlen(input) - 1] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting the shell...\n");
			break;
		}
		if (strcmp(input, "env") == 0)
		{
			print_environment();
			continue;
		}
		tokenize_input(input, args);
		find_and_execute_command(args);
	}
	return (0);
}
