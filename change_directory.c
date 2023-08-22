#include "shell.h"

/**
* correct_pwd - It is an updated pwd
*
* @current_path: It is a new path
* Return: 0 (successful)
*/

void correct_pwd(const char *current_path)
{
char *folder = getcwd(NULL, 0);
if (folder == NULL)
{
perror("getcwd");
return;
}

if (setenv("PWD", folder, 1) != 0)
{
perror("setenv");
}

free(folder);
}
/**
* change_directory - It is an corrected pwd
* @route: It is a pointer
* Return: 0
*/

void change_directory(const char *route)
{
if (chdir(route) != 0)
perror("chdir");

else
{
correct_pwd(route);
}
}
/**
* main - Entry point
* @argc: Number of arguments passed to program.
* @argv: An array of string.
*
* Return: 0
*/
int main(int argc_one, char *argv_one[])
{
const char *root_dir = getenv("HOME");
if (root_dir == NULL)
{
write(STDOUT_FILENO, "Error: HOME environment variable not set.\n", 43);
return (1);
}

const char *target_folder = argc_one > 1 ? argv_one[1] : root_dir;
if (strcmp(target_folder, "-") == 0)
{
const char *previous_folder = getenv("OLDPWD");
if (previous_folder == NULL)
{
write(STDOUT_FILENO, "Error: OLDPWD environment variable not set.\n", 40);
return (1);
}
target_folder = previous_folder;
write(STDOUT_FILENO, target_folder, strlen(target_folder));
write(STDOUT_FILENO, "\n", 1);
}

change_directory(target_folder);

return (0);
}
