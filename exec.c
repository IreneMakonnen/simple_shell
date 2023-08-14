#include "shell.h"
/* display_prompt - func dat print prompt text
 * display the prompt to user
 */

void display_prompt(void)
{
printf("Simple_Shell$ ");
fflush(stdout);
}
/**
* execute_command - Function that execute command
*
* @char: Command to execute
* exit te block
* @ strcspn: Remove a trailing newline char
* @ comma: Pointer to a character
* Return: if execution failed bring 1
* or 0 if successfull
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
printf("Execution of comma failed.\n");
return (1);
}

return (0);
}
/**
* main - Entry point
* @Handles end of file and exit the block
* Return: 0 (successful)
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

