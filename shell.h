#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 150
#define MAX_ARGS 15
#define MAX_INPUT_SIZE 1024
#define DATA_MANIPULATION 1024

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

typedef void (*builtin_function)(char **);

/**
 * struct mybuild - Structure with two members
 * @name: Pointer to constant string of name of built-in command
 * @func: Pointer to builtin_function
 */
typedef struct mybuild
{
        const char *name;
        builtin_function func;
} mybuild;

extern char **environ;
extern data_entry data_table[DATA_MANIPULATION];

void display_prompt(void); 
void copy_command(int n);
void execute_command(char **command, char **args);
char **splitstring(const char *input, const char *delimiters);
void linkedpath(char *path);
path_directory *convert_to_path(data_entry data);
char *findpathname(char *file);
void exithandling(char **arv);
int a_to_i(char *str);
void print_environment(void);
void free_struct(path_directory *head);
void free_argv(char **arv);
builtin_function check_build(char **args);
void exitshell(char **args);
void environment(char **args);
void find_and_execute_command(char **args);
int main(int argc, char *argv[]);
void change_directory(const char* route);
void correct_pwd(const char* current_path);
void parseString(const char *star);
void print_names(const char *our_names, size_t num_names);

#endif
