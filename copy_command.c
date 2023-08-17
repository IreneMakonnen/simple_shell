#include "shell.h"

/**
 * copy_command - Manages the copy (Ctrl+C) command
 * @n: Integer
 */
void copy_command(int n)
{
	if (n == SIGINT)
		puts("\n#cisfun$ ");
}
