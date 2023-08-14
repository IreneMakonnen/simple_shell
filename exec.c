#include "shell.h"

void display_prompt()
{
    printf("Simple_Shell$ ");
    fflush(stdout);
}
/**
 * execute_command - function that execute command
 * @char: check for end of file
 * exit te block
 * @strcspn: remove a trailing newline char
 *
 * Return: if execution failed bring 1
 * or 0 if successfull
 */

int execute_command(char *comma) {

    if (comma == NULL) {
        printf("\n");
        exit(0);
    }

    comma[strcspn(comma, "\n")] = '\0';

    int res = system(comma);

    if (res == -1) {
        printf("Execution of comma failed.\n");
        return 1;
    }

    return 0;
}
/**
 * main - Entry point
 * @Handles end of file and exit the block
 * Return: 0 (successful)
 */
int main(void) {
    char comma[MAX_COMMAND_LENGTH];

    while (1) {
        display_prompt();

        if (fgets(comma, sizeof(comma), stdin) == NULL) {
            printf("\n");
            break;
        }

        if (execute_command(comma) != 0) {
            printf("Command not found: %s\n", comma);
        }
    }

    return 0;
}
i
