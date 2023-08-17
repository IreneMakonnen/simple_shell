#include "shell.h"

ssize_t write(int fd, const void *buf, size_t count);
int main()
{
    const char *names = "Irene and Belinda\n";
    size_t names_length = strlen(names);

    write(STDOUT_FILENO, names, names_length);

    return (0);
}
