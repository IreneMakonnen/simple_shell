#include "shell.h"

/**
 * print_environment - Prints environment variables
 */
void print_environment(void)
{
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		printf("%s\n", *env_ptr);
		env_ptr++;
	}
}

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

/**
 * tokenize_input - Tokenizes user input into arguments
 * @input: String of user input
 * @args: Array to store the tokenized arguments
 */
void tokenize_input(char *input, char **args)
{
	int arg_count = 0;
	char *token = strtok(input, " ");

	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
}

/**
 * find_and_execute_command - Executes user's command
 * @args: Array of arguments containing the command to execute
 */
void find_and_execute_command(char **args)
{
	char *path = getenv("PATH"), *token = strtok(path, ":");;
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
