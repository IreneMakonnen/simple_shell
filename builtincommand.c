#include "shell.h"

const mybuild builtins[] = {
	{"exit", exitshell},
	{"env", environment},
	{NULL, NULL}
};

/**
 * check_build - Pointer to a function
 * @args: Array of strings
 * Return: 0 (Success)
 */
builtin_function check_build(char **args)
{
	int i;

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			return builtins[i].func;
		}
	}
	return (NULL);
}

/**
 * exitshell - Implements the built-in exit command
 * @args: Array of strngs
 */
void exitshell(char **args)
{
	int status;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		exit(status);
	}
	exit(0);
}

/**
 * environment -  Implements built-in env command
 * @args: Array of strings
 */
void environment(char **args)
{
	char **env;
	size_t len;

	(void)args;

	for (env = environ; *env != NULL; env++)
	{
		len = strlen(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
