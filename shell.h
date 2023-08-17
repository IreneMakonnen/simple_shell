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
#define DATA_MANIPULATION 1024

extern char **environ;
data_entry data_table[DATA_MANIPULATION];

int execute_command(char *comma); 
void display_prompt(void); 
void copy_command(int n);
void execute_command(char **command, char **args);
void linkedpath(char *path);
char *findpathname(char *file);
void exithandling(char **arv);
int a_to_i(char *str);
void print_environment(void);
void find_and_execute_command(char **args);

typedef struct
{
	char *dir;
	char *path;
} data_entry;

#endif /*SHELL_H*/
