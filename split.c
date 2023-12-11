#include "shell.h"
/**
 * separator - split command
 * @input: String gathered from stdin
 * Return: return strings to be used as commands
 */
char **separator(char *input)
{
int buffsize = BUFSIZE;

char *command;

if (input[0] == ' ' && input[strlen(input)] == ' ')
exit(0);
if (input == NULL)
return (NULL);
command = malloc(sizeof(char *) * buffsize);
if (!command)
{
free(command);
perror("hsh");
return (NULL);
}
command = _strtok(input, ";&");
{
command = _strtok(NULL, ";&");
}
command = NULL;
return (NULL);
}

