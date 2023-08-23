#include "shell.h"
/**
 * main - Entry point of program
 * Return: Always 0 (Success)
 */
int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, **av, *value, *pathname;
	size_t measure = 0;
	builtin_function f;
	path_directory *head = NULL;

	signal(SIGINT, copy_command);
	while (len != -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		
		len = getline(&buff, &measure, stdin);
		if (len == -1)
		{
			free(buff);
			break;
		}
		av = splitstring(buff, " \n");
		if (!av || !av[0])
			execute_command(av, NULL);
		else
		{
			value = getenv("PATH");
			linkedpath(value);
			head = convert_to_path(data_table[0]);
			pathname = findpathname(av[0]);
			f = check_build(av);
			if (f)
			{
				free(buff);
				f(av);
			}
			else if (!pathname)
			{
				execute_command(av, NULL);
				free_struct(head);
				free_argv(av);
				free(buff);
				exit(EXIT_FAILURE);
			}
			else
			{
				free(av[0]);
				av[0] = pathname;
				execute_command(av, av);
			}
		}
	}
	free_struct(head);
	free_argv(av);
	free(buff);
	return (0);
}

/**
 * copy_command - Manages the copy (Ctrl+C) command
 * @n: Integer
 */
void copy_command(int n)
{
	if (n == SIGINT)
		write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
