#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>


#define MAX_COMMAND_LENGTH 150
#define MAX_ARGS 64
#define MAX_INPUT_SIZE 1024

extern char **environ;
int execute_command(char *comma); 
void display_prompt(void); 
void print_environment(void);
void execute_command(char *command, char **args);
void tokenize_input(char *input, char **args);
void find_and_execute_command(char **args);


#endif /*SHELL_H*/
