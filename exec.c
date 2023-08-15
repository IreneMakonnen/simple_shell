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
* @comma: Its a command to execute.
* Return: 1 if execution failed
* or 0 if successful.
*/
int execute_command(char *comma)
{
if (comma == NULL)
{
printf("\n");
exit(0);
}
comma[strcspn(comma, "\n")] = '\0';
int res = system(comma);
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
printf("\n");
break;
}
if (execute_command(comma) != 0)
{
printf("Command not found: %s\n", comma);
}
}
return (0);
}
