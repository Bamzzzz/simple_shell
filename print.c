#include "shell.h"
/**
 * print_echo - print echo function
 * @cmd: command
 * Return: 0 Upon Success -1 Upon Failure
 */
int print_echo(char **cmd)
{
int status;
pid_t pid;
pid = fork();
if (pid == 0)
{
if (execve("/bin/echo", cmd, environ) == -1)
{
return (-1);
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
return (-1);
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
/**
 * print_number_int - print number integers using _putchar function
 * @n: number to be printed
 */
void print_number_int(int n)
{
unsigned int x = n;

if (n < 0)
{
_putchar('-');
x = -x;
}
if ((x / 10) > 0)
print_number(x / 10);

_putchar(x % 10 + '0');
}
/**
 * print_number - print unsigned numbers using _putchar function
 * @n: Unsigned numbers to be printed
 */
void print_number(unsigned int n)
{
unsigned int x = n;

if ((x / 10) > 0)
print_number(x / 10);

_putchar(x % 10 + '0');
}
