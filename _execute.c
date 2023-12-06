#include "shell.h"
/**
 * check_cmd - check for commands in predefined path
 * @cmd: array found in command strings
 * @input: to free input recieved from user
 * @c: execution function of Command Not Found
 * @argv: arguments before program starts
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
int wstatus;
pid_t pid;

if (*cmd == NULL)
return (EXIT_FAILURE);
pid = fork();
if (pid == -1)
{
perror("Error");
return (-1);
}
if (pid == 0)
{
if (access(cmd[0], R_OK) != 0)
{
print_error(cmd[0], c, argv);
free_all(cmd, input);
exit(127);
}
if (execve(*cmd, cmd, environ) == -1)
return (2);
else
return (0);
}
wait(&wstatus);
if (WIFEXITED(wstatus))
{
if (WEXITSTATUS(wstatus) == 0)
return (0);
else if (WEXITSTATUS(wstatus) == 2)
return (2);
else if (WEXITSTATUS(wstatus) == 127)
return (127);
}
return (127);
}

/**
 * signal_to_handle - configures ^C not to terminate our shell
 * @sig: signal to handle
 */
void signal_to_handle(int sig)
{
if (sig == SIGINT)
{
printf("\n$ ");
}
}
