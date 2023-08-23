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
 * convert_to_path - Converts data_entry to path_directory
 * @data: data_entry instance
 * Return: path_directory instance
 */
path_directory *convert_to_path(data_entry data)
{
	path_directory *node = malloc(sizeof(path_directory));
	if (!node)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	node->dir = strdup(data.dir);
	node->next = NULL;
	return (node);
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
		data_index++;
	}
	return (NULL);
}
