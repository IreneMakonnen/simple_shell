#include <shell.h>

/**
 * main - display prompt
 * handle the “end of file” condition (Ctrl+D)
 * Return: 0
 */
int main(void)
{
char bar[MAX_COMMAND_LENGTH];

while (1)
{
write(STDOUT_FILENO, "$", 2);

if (fgets(bar, MAX_COMMAND_LENGTH, stdin) == NULL)
{
write(STDOUT_FILENO, "\n", 1);
break;
}
bar[strcspn(bar, "\n")] = '\0';
pid_t pid = fork();
if (pid < 0)
{
perror("Fork failed");
exit(1);
}
else if (pid == 0)
{
if (access(bar, X_OK) == 0)
{
execve(bar, NULL, NULL);
perror("Execution failed");
}
else
{
write(STDOUT_FILENO, "Command not found: ", 25);
write(STDOUT_FILENO, bar, strlen(bar));
write(STDOUT_FILENO, "\n", 1);
}
_exit(1);
}
else
{
int pro;
waitpid(pid, &pro, 0);
}
}
return (0);
}
