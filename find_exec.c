#include "shell.h"

/**
 * find_and_execute_command - Executes user's command
 * @args: Array of arguments containing the command to execute
 */
void find_and_execute_command(char **args)
{
	char *way = getenv("PATH");
	char *coup = strtok(path, ":");
	char len_path[MAX_INPUT_SIZE];

	if (way == NULL)
	{
		perror("Unable to access PATH");
		return;
	}
	while (coup != NULL)
	{
		snprintf(len_path, sizeof(len_path), "%s/%s", coup, args[0]);
		if (access(len_path, X_OK) == 0)
		{
			execute_command(len_path, args);
			return;
		}
		coup = strtok(NULL, ":");
	}
	printf("Command not found: %s\n", args[0]);
}
