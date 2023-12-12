#include "shell.h"
/**
 * treat_file - treat file commands
 * @line: Line in the file
 * @count: count errors present in the code
 * @fp: descriptor
 * @argv: arguments
 */
void treat_file(char *line, int count, FILE *fp, char **argv)
{
int stat = 0;
char **cmd;

cmd = parse_cmd(line);
if (_strncmp(cmd[0], "exit", 4) == 0)
exit_bul_for_file(cmd, line, fp);
else if (check_builtin(cmd) == 0)
{
stat = handle_builtin(cmd, stat);
free(cmd);
}
else
{
stat = check_cmd(cmd, line, count, argv);
free(cmd);
}
}
/**
 * read_file - read file commands
 * @file: file commands
 * @argv: arguments
 * Return: -1 or 0
 */
void read_file(char *file, char **argv)
{
int count = 0;
FILE *fp;
char *line = NULL;
size_t len = 0;
fp = fopen(file, "r");
if (fp == NULL)
{
error_file(argv, count);
exit(127);
}
while ((getline(&line, &len, fp)) != -1)
{
count++;
treat_file(line, count, fp, argv);
}
if (line)
free(line);
fclose(fp);
exit(0);
}
/**
 * exit_bul_for_file - exit file input
 * @line: line from a file
 * @cmd: command
 * @fd: descriptor
 */
void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
int i = 0;
int status;

if (cmd[i] == NULL)
{
free(cmd);
free(line);
fclose(fd);
exit(errno);
}
while (cmd[1][i])
{
if (_isalpha(cmd[1][i++]) < 0)
perror("unwanted number");
}
status = _atoi(cmd[1]);
free(cmd);
free(line);
fclose(fd);
exit(status);
}
