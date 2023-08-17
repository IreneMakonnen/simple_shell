#include "shell.h"

/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
const char *names = "Irene and Belinda\n";
size_t names_len = strlen(names);

write(STDOUT_FILENO, names, names_len);

return (0);
}

