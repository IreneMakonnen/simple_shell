#include "shell.h"

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
