#include "shell.h"
/**
 * help_env - displays environment information
 */
void help_env(void)
{
char *msg = "env: env\n\tPrints the current environment.\n";

write(STDOUT_FILENO, msg, strlen(msg));
}
/**
 * display_help - display help for builtin command
 * @cmd: command
 * @st: status
 * Return: 0 Success
 */
int display_help(char **cmd, __attribute__((unused))int st)
{
if (!cmd[1])
help_all();
else if (_strcmp(cmd[1], "env") == 0)
help_env();
else if (_strcmp(cmd[1], "setenv") == 0)
help_setenv();
else if (_strcmp(cmd[1], "unsetenv") == 0)
help_unsetenv();
else if (_strcmp(cmd[1], "help") == 0)
help_help();
else if (_strcmp(cmd[1], "alias") == 0)
help_alias();
else if (_strcmp(cmd[1], "cd") == 0)
help_cd();
else if (_strcmp(cmd[1], "exit") == 0)
help_exit();
return (0);
}
/**
 * help_setenv - displays setenv information on the shell
 */
void help_setenv(void)
{
char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

write(STDOUT_FILENO, msg, strlen(msg));
msg = "environment variable, or modifies an existing one.\n\n";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "\tUpon failure, prints a message to stderr.\n";
write(STDOUT_FILENO, msg, strlen(msg));
}
/**
 * help_unsetenv - displays unsetenv information
 * 'unsetenv'
 */
void help_unsetenv(void)
{
char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

write(STDOUT_FILENO, msg, strlen(msg));
msg = "environmental variable.\n\n\tUpon failure, prints a ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "message to stderr.\n";
write(STDOUT_FILENO, msg, strlen(msg));
}
