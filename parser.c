#include "shell.h"
/**
 * parse_cmd - Parses the command
 * @input: string input gathered
 * Return: return strings to be used as arguments
 */
char **parse_cmd(char *input)
{
int i;
char **arguments;
char *argument;
int buffsize = BUFSIZE;

if (input[0] == ' ' && input[_strlen(input)] == ' ')
exit(0);
if (input == NULL)
return (NULL);
arguments = malloc(sizeof(char *) * buffsize);
if (!arguments)
{
free(arguments);
perror("hsh");
return (NULL);
}
argument = _strtok(input, "\n\t\r\a ");
for (i = 0; argument; i++)
{
arguments[i] = argument;
argument = _strtok(NULL, "\n\t\r\a ");
}
arguments[i] = NULL;

return (arguments);
}



