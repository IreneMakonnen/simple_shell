#include "shell.h"
/**
* parseString - func dat tokenize a string
* @star: It is a pointer
* Return: 0
*/

void parseString(const char *star)
{
	const char *deli_miter = "/";
	char numLen[264];
	char *tok;
	char *par;

	if (star == NULL)
		return;

	strcpy(numLen, star);

	tok = strtok_r(numLen, deli_miter, &par);
	while (tok != NULL)
	{
		write(STDOUT_FILENO, tok, strlen(tok));
		write(STDOUT_FILENO, "\n", 1);
		tok = strtok_r(NULL, deli_miter, &par);
	}
}

/**
 * main - Entry point
 * Return: 0 (successfully)
 */

int main(void)
{
	const char *star = "/usr/local/bin";

	parseString(star);

	return (0);
}
