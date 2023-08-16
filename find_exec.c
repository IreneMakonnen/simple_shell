#include "shell.h"

/**
 * find_and_execute_command - Executes user's command
 * @args: Array of arguments containing the command to execute
 */
void find_and_execute_command(char **args)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");
	char full_path[MAX_INPUT_SIZE];

	if (path == NULL)
	{
		perror("Unable to access PATH");
		return;
	}
	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, args[0]);
		if (access(full_path, X_OK) == 0)
		{
			execute_command(full_path, args);
			return;
		}
		token = strtok(NULL, ":");
	}
	printf("Command not found: %s\n", args[0]);
}
