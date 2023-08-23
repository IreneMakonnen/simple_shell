#include "shell.h"

/**
* _getline - Add to buffer if emmpty
* input end hold out
* len end hold remove the len string
* Return: Null
*/


char *_getline(void)
{
static char buff[MAX_INPUT_SIZE];
static int buFF_ind;
static int buFF_char;

char *numLen = NULL;
int len_Ind = 0;
int a;

while (1)
{
if (buff_index >= buFF_char)
{
buFF_char = read(STDIN_FILENO, buff, MAX_INPUT_SIZE);
buFF_ind = 0;
if (buFF_char == 0)
{
if (len_Ind == 0)
{
return (NULL);
}
break;
}
}

a = buff[buFF_ind++];
if (a == '\n')
{
numLen[len_Ind] = '\0';
break;
}

numLen = realloc(numLen, (len_Ind + 1) * sizeof(char));
numLen[len_Ind++] = a;
}

return (numLen);
}
/**
* main - Entry point
* Return: 0 (successful)
*/
int main(void)
{
write(STDOUT_FILENO, "Enter a len of text: ", 23);

char *numLen = _getline();
if (numLen != NULL)
{
write(STDOUT_FILENO, "Len: ", 6);
write(STDOUT_FILENO, numLen, strlen(numLen));
write(STDOUT_FILENO, "\n", 1);
free(numLen);
}
else
{
write(STDOUT_FILENO, "No input received.\n", 20);
}

return (0);
}
