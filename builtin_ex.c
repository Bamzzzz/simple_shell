#include "shell.h"
/**
 * change_dir - change in directory
 * @cmd: command
 * @st: status of executed last command
 * Return: 0 on success 1 if failed
 */
int change_dir(char **cmd, __attribute__((unused))int st)
{
int value = -1;
char cwd[PATH_MAX];

if (cmd[1] == NULL)
value = chdir(getenv("HOME"));
else if (_strcmp(cmd[1], "-") == 0)
{
value = chdir(getenv("OLDPWD"));
}
else
value = chdir(cmd[1]);

if (value == -1)
{
perror("hsh");
return (-1);
}
else if (value != -1)
{
getcwd(cwd, sizeof(cwd));
setenv("OLDPWD", getenv("PWD"), 1);
setenv("PWD", cwd, 1);
}
return (0);
}
/**
 * history_dis - display history
 * @c: command
 * @st: status of executed command
 * Return: 0 success or -1 if fail
 */
int history_dis(__attribute__((unused))char **c, __attribute__((unused))int st)
{
char *filename = "simple_shell code";
int counter = 0;
FILE *fp;
char *line = NULL;
char *er;
size_t len = 0;

fp = fopen(filename, "r");
if (fp == NULL)
{
return (-1);
}
while ((getline(&line, &len, fp)) != -1)
{
PRINT(line);
PRINT(" ");
counter++;
er = _itoa(counter);
PRINT(er);
free(er);
}
if (line)
free(line);
fclose(fp);
return (0);
}
/**
 * dis_env - display variable environment
 * @cmd: command
 * @st: status of executed last command
 * Return: Always 0
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int st)
{
int len;
size_t i;

for (i = 0; environ[i] != NULL; i++)
{
write(1, environ[i], len);
write(STDOUT_FILENO, "\n", 1);
len = strlen(environ[i]);
}
return (0);
}
/**
 * echo_bul - execute echo built character
 * @st: status of last command
 * @cmd: command
 * Return: Always 1
 */
int echo_bul(char **cmd, int st)
{
char *path;
unsigned int pid = getppid();

if (_strncmp(cmd[1], "$?", 2) == 0)
{
print_number_int(st);
PRINT("\n");
}
else if (_strncmp(cmd[1], "$$", 2) == 0)
{
PRINT("\n");
print_number(pid);
}
else if (_strncmp(cmd[1], "$PATH", 5) == 0)
{
path = _getenv("PATH");
PRINT(path);
PRINT("\n");
free(path);
}
return (print_echo(cmd));

return (1);
}
