#include "shell.h"
/**
 * _getline - all versions
 *
 * @in_put: explanation
 * @num_malloc: version
 * @pro: the exit
 * Return: 0 on smaller than -1 if fail
 */
ssize_t _getline(char **in_put, size_t *num_malloc, int pro)
{
	ssize_t num_char;

	prompt();
	num_char = getline(in_put, num_malloc, stdin);
	if (num_char == -1)
	{
		free(in_put);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(pro);
	}
	return (num_char);
}
