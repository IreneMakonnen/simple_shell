#include "shell.h"
/**
 * main - Entry point
 * Return: 0
 */

int main(void)
{
	const char *names = "Irene", "Belinda";
	size_t numLen = strlen(names);

	write(STDOUT_FILENO, numLen, names);

	return (0);
}
