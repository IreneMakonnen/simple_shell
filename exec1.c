#include "shell.h"

/**
 * execute_command - Executes command with specified arguments
 * @command: Command to execute
 * @args: Array of arguments for the command
 */
void execute_command(char *command, char **args)
{
	int status;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execvp(command, args);
		perror("Execution failed");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
