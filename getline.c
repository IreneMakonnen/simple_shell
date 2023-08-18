#include "shell.h"

/**
* our_getline - Add to buffer if emmpty
* input end hold out
* len end hold remove the len string
* Return: Null
*/


char *our_getline(void)
{
static char buff[MAX_INPUT_SIZE];
static int buff_index;
static int chars_in_buff;

char *len = NULL;
int len_index = 0;
int n;

while (1)
{
if (buff_index >= chars_in_buff)
{
chars_in_buff = read(STDIN_FILENO, buff, MAX_INPUT_SIZE);
buff_index = 0;
if (chars_in_buff == 0)
{
if (len_index == 0)
{
return (NULL);
}
break;
}
}

n = buff[buff_index++];
if (n == '\n')
{
len[len_index] = '\0';
break;
}

len = realloc(len, (len_index + 1) * sizeof(char));
len[len_index++] = n;
}

return (len);
}
/**
* main - Entry point
* Return: 0 (successful)
*/
int main(void)
{
write(STDOUT_FILENO, "Enter a len of text: ", 23);

char *len = our_getline();
if (len != NULL)
{
write(STDOUT_FILENO, "Len: ", 6);
write(STDOUT_FILENO, len, strlen(len));
write(STDOUT_FILENO, "\n", 1);
free(len);
}
else
{
write(STDOUT_FILENO, "No input received.\n", 20);
}

return (0);
}
