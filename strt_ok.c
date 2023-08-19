#include "shell.h"
/**
* parseString - func dat tokenize a string
* @strin: It is a pointer
* Return: 0
*/

void parseString(const char *strin)
{
	const char *del = "/";
	char len[260];

	strcpy(len, strin);

	char *coup;

	coup = strtok(len, del);

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

parseString(pat);

return (0);
}
