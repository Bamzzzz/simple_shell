#include "shell.h"
/**
 * handle_builtin - handle built in commands
 * @cmd: command strings
 * @st: status of command
 * Return: -1 Failure 0 Success
 */
int handle_builtin(char **cmd, int st)
{
builtin built_in[] = {
{"cd", change_dir},
{"env", dis_env},
{"help", display_help},
{"echo", echo_bul},
{"history", history_dis},
{NULL, NULL}
};
int i = 0;

while ((built_in + i)->command)
{
if (_strcmp(cmd[0], (built_in + i)->command) == 0)
{
return ((built_in + i)->function(cmd, st));
}
i++;
}
return (-1);
}
/**
 * check_builtin - Checks for builtin character
 * @cmd: command
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
builtin fun[] = {
{"cd", NULL},
{"help", NULL},
{"echo", NULL},
{"env", NULL},
{"history", NULL},
{NULL, NULL}
};
int i = 0;

if (*cmd == NULL)
{
return (-1);
}
while ((fun + i)->command)
{
if (_strcmp(cmd[0], (fun + i)->command) == 0)
return (0);
i++;
}
return (-1);
}
/**
 * exit_bul - exit commands for built-in
 * @cmd: command strings array
 * @input: inputs to be freed
 * @argv: arguments before program starts
 * @c: execution count
 * @stat: status exit
 */
void exit_bul(char **cmd, char *input, char **argv, int c, int stat)
{
int status, i = 0;

if (cmd[1] == NULL)
{
free(input);
free(cmd);
exit(stat);
}
while (cmd[1][i])
{
if (_isalpha(cmd[1][i++]) != 0)
{
_prerror(argv, c, cmd);
free(cmd);
free(input);
exit(2);
}
else
{
status = _atoi(cmd[1]);
if (status == 2)
{
_prerror(argv, c, cmd);
free(input);
free(cmd);
exit(status);
}
}
}
}
