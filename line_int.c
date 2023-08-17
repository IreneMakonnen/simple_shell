#include "shell.h"
/**
 * main - Entry point of program
 * Return: Always 0 (Success)
 */
int main(void)
{
	size_t len = 0;
	char *buff = NULL;
	size_t measure = 0;
	char **av = NULL;
	char *value, *pathname;
	void (*f)(char **);
	path_directory *head = NULL;

	signal(SIGINT, copy_command);
	while (len != EOF)
	{
		if (isatty(STDIN_FILENO))
			puts("#cisfun$ ");
		len = getline(&buff, &measure, stdin);
		EOF(len, buff);
		av = splitstring(buff, " \n");
		if (!av || !av[0])
			execute_command(av, NULL);
		else
		{
			value = getenv("PATH");
			head = linkedpath(value);
			pathname = which(av[0], head);
			f = check_build(av);
			if (f)
			{
				free(buff);
				f(av);
			}
			else if (pathname)
			{
				free(av[0]);
				av[0] = pathname;
				execute(av, av);
			}
			else if (!pathname)
				execute_command(av, NULL);
		}
	}
	free_struct(head);
	free_argv(av);
	free(buff);
	return (0);
}
