#include "shell.h"
/**
 * _getenv - search for environment variable by name
 * @name: variable name for environment
 * Return: The value of the environment variable
 */
char *_getenv(char *name)
{
int i, j, k;
size_t name_len, value_len;
char *value;

name_len = strlen(name);
for (i = 0 ; environ[i]; i++)
{
value = malloc(sizeof(char) * value_len);
value_len = strlen(environ[i]) - name_len;

if (!value)
{
perror("unable to alloc");
free(value);
return (NULL);
}
j = 0;
for (k = name_len + 1; environ[i][k]; k++, j++)
{
value[j] = environ[i][k];
}
value[j] = '\0';
}
return (value);
return (NULL);
}
