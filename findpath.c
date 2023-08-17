#include "shell.h"

/**
 * linkedpath - Links path directories
 * @path: String of values of paths
 */
void linkedpath(char *path)
{
	char *token;
	int data_index = 0;

	token = strtok(path, ":");
	while (token)
	{
		data_table[data_index].dir = strdup(token);
		data_table[data_index].path = strdup(token);
		token = strtok(NULL, ":");
		data_index++;
	}
}

/**
 * findpathname - Finds the name of PATH
 * @file: File name
 * @head: Head of structure for path directories
 * Return: Pathname or NULL
 */
char *findpathname(char *file)
{
	int data_index = 0;
	char *totalpath;

	while (data_table[data_index].dir != NULL)
	{
		totalpath = malloc(strlen(data_table[data_index].path) + strlen(file) + 2);
		if (totalpath == NULL)
			exit(EXIT_FAILURE);

		strcpy(totalpath, data_table[data_index].path);
		strcat(totalpath, "/");
		strcat(totalpath, file);

		if (access(totalpath, X_OK) == 0)
			return (totalpath);

		free(totalpath);
		data_ndex++;
	}
	return (NULL);
}
