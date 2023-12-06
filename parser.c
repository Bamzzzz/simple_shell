#include "shell.h"
/**
 * parse_cmd - Parses the command
 * @input: string input gathered
 * Return: Parsed strings to be used as arguments
 */
char **parse_cmd(char *input)
{
int i;
char **argv;
int buffsize = BUFSIZE;

if (input[0] == ' ' && input[strlen(input)] == ' ')
exit(0);
if (input == NULL)
return (NULL);
argv = malloc(sizeof(char *) * buffsize);
if (!argv)
{
free(argv);
perror("hsh");
return (NULL);
}
for (i = 0; argv; i++)
argv[i] = NULL;
return (argv);
}
