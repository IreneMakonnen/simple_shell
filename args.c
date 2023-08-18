#include "shell.h"

/**
* display_prompt - Func dat displays prompt to user.
*/
void display_prompt(void)
{
printf("Simple_Shell$ ");
fflush(stdout);
}

/**
* execute_command - Func dat executes a command.
*
* @comma: Command to execute.
* Return: 1 if execution failed, 0 if successful.
*/
int execute_command(char *comma)
{
if (comma == NULL)
{
printf("\n");
exit(0);
}

comma[strcspn(comma, "\n")] = '\0';

/**
* Turning command to command and arguments
*/
char *arguments[MAX_COMMAND_LENGTH];
int args_tot = 0;

char *coup = strtok(comma, " ");
while (coup != NULL && args_tot < MAX_COMMAND_LENGTH - 1)
{
arguments[args_tot] = coup;
args_tot++;
coup = strtok(NULL, " ");
}
arguments[args_tot] = NULL;
/**
* Set the last argument to NULL for execvp
*/

int res = execvp(arguments[0], arguments);

if (res == -1)
{
printf("Execution of command failed.\n");
return (1);
}

return (0);
}

/**
* main - Entry point of the program.
*
* Handles end of file and exits the block.
* Return: 0 (successful).
*/
int main(void)
{
char comma[MAX_COMMAND_LENGTH];

while (1)
{
display_prompt();

if (fgets(comma, sizeof(comma), stdin) == NULL)
{
write(STDOUT_FILENO, "\n");
break;
}

if (execute_command(comma) != 0)
{
write(STDOUT_FILENO, "Command not found: %s\n", comma);
}
}

return (0);
}
