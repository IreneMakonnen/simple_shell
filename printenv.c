#include "shell.h"

/**
 * print_environment - Prints environment variables
 */
void print_environment(void)
{
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		write(STDOUT_FILENO, *env_ptr, strlen(*env_ptr));
		write(STDOUT_FILENO, "\n", 1);
		env_ptr++;
	}
}
