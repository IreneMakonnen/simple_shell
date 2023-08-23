#include "shell.h"

void print_names(const char *our_names, size_t num_names);
/**
 * main - Entry point
 * Return: 0 successfully
 */
int main(void)

	const char *our_names[] = {
		"Irene",
		"Belinda"
	};
	size_t *num_names = sizeof(our_names) / sizeof(our_names[0]);

	print_names(our_names[0], num_names);

	return (0);
/**
 * print_names - modified to iterate
 * over our names correctly.
 * @our_names: pointer
 * @num_names: size
 */

void print_names(const char *our_names, size_t num_names)

	for (size_t a = 0; a < num_names; a++)
	{
		size_t len_gth = strlen(our_names);

		write(STDOUT_FILENO, our_names, len_gth);
		write(STDOUT_FILENO, "\n", 1);
		our_names += len_gth + 1;/* Move the pointer to next name */
}
