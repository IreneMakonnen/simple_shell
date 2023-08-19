#include "shell.h"
/**
* parse_string - func dat tokenize a string
* @strin: It is a pointer
* Return: 0
*/

void parse_string(const char *strin)
{
	const char *del = "/";
	char len[260];

	strcpy(len, strin);

	char *coup = strtok(len, del);

	while (coup != NULL)
{
	write(STDOUT_FILENO, coup, strlen(coup));
	write(STDOUT_FILENO, "\n", 1);
	coup = strtok(NULL, del);
}
}
/**
* main - Entry point
* Return: 0
*/

int main(void)
{
	const char *pat = "/usr/local/bin";

parse_string(pat);

return (0);
}
