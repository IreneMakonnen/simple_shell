#include "shell.h"

/**
 * execute_command - Executes command with specified arguments
 * @command: Command to execute
 * @args: Array of arguments for the command
 */
void execute_command(char **command, char **args)
{
	int status, n;

	if (!command || !argv[0])
		return;

	n = fork();
	if (d == 0)
	{
		execve(command[0], args, environ);
		perror(command[0]);
		exit(EXIT_FAILURE);
	}
	if (n == -1)
		perror(getenv("_"));

	wait(&status);
}
