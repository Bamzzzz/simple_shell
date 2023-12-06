#include "shell.h"
/**
 * print_error - print out error
 * @input: input
 * @counter: count of shell loop
 * @argv: arguments
 */

void print_error(char *input, int counter, char **argv)
{
char *er;
PRINT(argv[0]);
PRINT(": ");
er = _itoa(counter);
free(er);
PRINT(input);
PRINT(": not found\n");
PRINT(": ");
}
/**
 *  _prerror - print error
 * @argv: argument
 * @c: count
 * @cmd:command strings
 */
void _prerror(char **argv, int c, char **cmd)
{
char *er = _itoa(c);
PRINT(argv[0]);
PRINT(": ");
PRINT(er);
PRINT(": ");
PRINT(cmd[0]);
PRINT(": Illegal number: ");
PRINT(cmd[1]);
PRINT("\n");
free(er);
}
/**
 * error_file - print error file
 * @argv: argv
 * @c: count
 */
void error_file(char **argv, int c)
{
char *er = _itoa(c);

PRINT(argv[0]);
PRINT(": ");
PRINT(er);
PRINT(": Can't open ");
PRINT(argv[1]);
PRINT("\n");
free(er);
}
