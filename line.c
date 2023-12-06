#include "shell.h"
/**
 * hashtag_handler - function that removes everything after '#' or '$' sysmbol
 * @buff: input buffer
 * Return: nothing
 */
void hashtag_handler(char *buff)
{
int i;
for (i = 0; buff[i] != '\0'; i++)
{
if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
{
buff[i] = '\0';
}
}
}
/**
 * enter - enter newline character input
 * @string: string to be handled in character
 * Return: Empty string
 */
char *enter(char *string)
{
free(string);
return ("\0");
}
/**
 * _getline - read standard input
 * Return: the input on a buffer
 */
char *_getline()
{
char c = 0, *buffer, *buf;
int i, rd, buffsize = BUFSIZE;
buffer = malloc(buffsize);
if (buffer == NULL)
{
free(buffer);
return (NULL);
}
for (i = 0; c != EOF && c != '\n'; i++)
{
rd = read(STDIN_FILENO, &c, 1);
fflush(stdin);
if (rd == 0)
{
free(buffer);
exit(EXIT_SUCCESS);
}
buffer[i] = c;
if (buffer[0] == '\n')
return (enter(buffer));
if (i >= buffsize)
{
buffer = realloc(buffer, (buffsize + 2));
if (buffer == NULL)
{
free(buffer);
return (NULL);
}
}
}
buffer[i] = '\0';
buf = space(buffer);
free(buffer);
hashtag_handler(buf);
return (buf);
}
/**
 * space - modifies the string to remove whitespaceses
 * @str: strings to be modifies
 * Return: Returns the modified string
 */
char *space(char *str)
{
int i, j = 0;
char *buff;

buff = malloc(sizeof(char) * (strlen(str) + 1));
if (buff == NULL)
{
free(buff);
return (NULL);
}
for (i = 0; str[i] == ' '; i++)
;
for (; str[i + 1] != '\0'; i++)
{
buff[j] = str[i];
j++;
}
buff[j] = '\0';
if (buff[0] == '\0' || buff[0] == '#')
{
free(buff);
return ("\0");
}
return (buff);
}
