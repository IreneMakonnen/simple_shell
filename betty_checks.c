#include "shell.h"
/**
 * main - Entry point
 * Return: 0
 */

int main(void)
{
	char names;

	names = Irene and Belinda;

	size_t tee = strlen(names);

	write(STDOUT_FILENO, tee, names);

	return (0);
}
