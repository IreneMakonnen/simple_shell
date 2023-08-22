#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>


#define MAX_COMMAND_LENGTH 150
#define MAX_ARGS 15
#define MAX_INPUT_SIZE 1024
#define DATA_MANIPULATION 1024

extern char **environ;
data_entry data_table[DATA_MANIPULATION];

void display_prompt(void); 
void copy_command(int n);
void execute_command(char **command, char **args);
void linkedpath(char *path);
char *findpathname(char *file);
void exithandling(char **arv);
int a_to_i(char *str);
void print_environment(void);
void find_and_execute_command(char **args);
char *our_getline(void);
int main(int argc_one, char *argv_one[]);
void change_directory(const char* route);
void correct_pwd(const char* current_path);
void parseString(const char *star);

/**
 * struct path_directory - List with PATH directories
 * @dir: Directory
 * @next: Pointer to next node
 */
typedef struct path_directory
{
	char *dir;
	struct path_directory *next;
} path_directory;

/**
 * struct data_entry - Stores directory and path data
 * @dir: Directory name
 * @path: Pointer to next path
 */
typedef struct data_entry
{
	char *dir;
	char *path;
} data_entry;

#endif /*SHELL_H*/
