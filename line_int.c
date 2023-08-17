#include "shell.h"

/**
 * copy_command - Manages the copy (Ctrl+C) command
 * @n: Integer
 */
void copy_command(int n)
{
	if (n == SIGINT)
		puts("\n#cisfun$ ");
}

/**
 * main - Entry point of program
 * Return: Always 0 (Success)
 */
int main(void)
{
	size_t len = 0;
	char *buff = NULL;
	size_t measure = 0;

	signal(SIGINT, copy_command);
	while (len != EOF)
	{
		if (isatty(STDIN_FILENO))
			puts("#cisfun$ ");
		len = getline(&buff, &size, stdin);
	}

	return (0);
}
