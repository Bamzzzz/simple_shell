#include "shell.h"
/**
 * create_envi - creates enviroment variables
 * @envi: enviroment variables
 */
void create_envi(char **envi)
{
int i;
for (i = 0; environ[i]; i++)
envi[i] = NULL;
}
/**
 * free_env - frees enviroment variables
 * @env:  Array of Environment variables
 */
void free_env(char **env)
{
int i;
for (i = 0; env[i]; i++)
{
free(env[i]);
}
}
