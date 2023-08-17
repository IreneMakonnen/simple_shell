#include "shell.h"

/**
 * exithandling - Exits the shell
 * @arv: Array of arguments
 */
void exithandling(char **arv)
{
	int status = 0;

	if (arv[1])
	{
		status = a_to_i(arv[1]);
		if (status <= -1)
		status = 2;
	}
	freearv(arv);
	free_list(head);
	free(buff);
	exit(status);
}

/**
 * a_to_i - Converts string to integer
 * @str: Pointer to string
 * Return: Integer
 */
int a_to_i(char *str)
{
	int n = 0;
	int sign = (*str == '-') ? -1 : 1;

	if (*str == '-' || *str == '+')
		str++;

	while (*str >= '0' && *str <= '9')
	{
		integer = integer * 10 + (*str - '0');
		str++;
	}
	return (sign * n);
}
