#include "shell.h"

/**
 * execute_command - Executes command with specified arguments
 * @command: Command to execute
 * @args: Array of arguments for the command
 */
void execute_command(char **command, char **args)
{
	int pro, n;

	if (!command || !command[0])
		return;

	n = fork();
	if (n == 0)
	{
		execve(command[0], args, environ);
		perror(command[0]);
		exit(EXIT_FAILURE);
	}
	if (n == -1)
		perror(getenv("_"));

	wait(&pro);
}

/**
 * splitstring - Splits string into tokens
 * @input: String set to be split
 * @delimiters: Delimiter
 * Return: Array of strings
 */
char **splitstring(const char *input, const char *delimiters)
{
	int max_tokens = 10, num_tokens = 0, i;
	char *copy, *token;
	char **tokens = (char **)malloc(max_tokens * sizeof(char *));

	if (tokens == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	copy = strdup(input);
	if (copy == NULL)
	{
		perror("Memory allocation error");
		free(tokens);
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, delimiters);
	num_tokens = 0;
	while (token != NULL)
	{
		tokens[num_tokens] = strdup(token);
		if (tokens[num_tokens] == NULL)
		{
			perror("Memory allocation error");
			for (i = 0; i < num_tokens; i++)
				free(tokens[i]);
			free(tokens);
			free(copy);
			exit(EXIT_FAILURE);
		}
		num_tokens++;
		if (num_tokens >= max_tokens)
		{
			max_tokens *= 2;
			tokens = realloc(tokens, max_tokens * sizeof(char *));
			if (tokens == NULL)
			{
				perror("Memory allocation error");
				for (i = 0; i < num_tokens; i++)
					free(tokens[i]);
				free(tokens);
				free(copy);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delimiters);
	}
	tokens[num_tokens] = NULL;
	free(copy);
	return (tokens);
}
