#include "shell.h"
/**
 * _strtok - function that extracts token
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
unsigned int i;
static char *new_token;
static char *tokens;

if (str != NULL)
new_token = str;
tokens = new_token;
if (tokens == NULL)
return (NULL);
for (i = 0; tokens[i] != '\0'; i++)
{
if (check_delim(tokens[i], delim) == 0)
break;
}
if (new_token[i] == '\0' || new_token[i] == '#')
{
new_token = NULL;
return (NULL);
}
tokens = new_token + i;
new_token = tokens;
for (i = 0; new_token[i] != '\0'; i++)
{
if (check_delim(new_token[i], delim) == 1)
break;
}
if (new_token[i] == '\0')
new_token = NULL;
else
{
new_token[i] = '\0';
new_token = new_token + i + 1;
if (*new_token == '\0')
new_token = NULL;
}
return (tokens);
}
/**
 * check_delim - function that checks for character match
 * @c: character to check withun the string
 * @str: string of delimiters
 * Return: 1 on success, 0 on failure
 */
unsigned int check_delim(char c, const char *str)
{
unsigned int i;
for (i = 0; str[i] != '\0'; i++)
{
if (c == str[i])
return (1);
}
return (0);
}
