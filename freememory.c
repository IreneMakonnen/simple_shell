#include "shell.h"

/**
 * free_struct - Frees linked list
 * @head: Pointer to linked list
 */
void free_struct(path_directory *head)
{
    path_directory *storage;

    while (head)
    {
        storage = head->next;
        free(head->dir);
        free(head);
        head = storage;
    }
}

/**
 * free_argv - Frees array of argument vectors
 * @arv: Argument vectors
 */
void free_argv(char **arv)
{
    int i;

    for (i = 0; arv[i]; i++)
        free(arv[i]);
    free(arv);
}
