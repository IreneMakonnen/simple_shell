#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>



#define MAX_COMMAND_LENGTH 150
#define MAX_ARGUMENTS 15

int execute_command(char *comma); 
void display_prompt(); 
#endif
