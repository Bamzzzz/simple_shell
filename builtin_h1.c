#include "shell.h"
/**
 * help_all - displays all possible builtin shell commands
 */
void help_all(void)
{
char *msg = "shell\nshell commands are defined internally.\n";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "type 'help' to see this list.\ntype 'help name' to find ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "out more about the function 'name'.\n\n alias \t";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "alias [NAME[='VALUE'] ...]\n  cd \tcd ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "[DIRECTORY]\n  exit \texit [STATUS]\n env \tenv";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "\n  setenv \tsetenv [VARIABLE] [VALUE]\n unsetenv\t";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "unsetenv [VARIABLE]\n";
write(STDOUT_FILENO, msg, strlen(msg));
}
/**
 * help_cd - cd information on the shell by builtin command to be displayed
 */
void help_cd(void)
{
char *msg = "cd: cd [DIRECTORY]\n\tchange the current directory of the";
write(STDOUT_FILENO, msg, strlen(msg));
msg = " process to DIRECTORY.\n\n\tif no argument is given, the ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "command is interpreted as cd $HOME. if the argument '-' is";
write(STDOUT_FILENO, msg, strlen(msg));
msg = " given, the command is interpreted as cd $OLDPWD.\n\n";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "\tThe environment variables PWD and OLDPWD are updated ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "after a change of directory.\n";
write(STDOUT_FILENO, msg, strlen(msg));
}
/**
 * help_exit - display exit information
 */
void help_exit(void)
{
char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "STATUS argument is the integer used to exit the shell.";
write(STDOUT_FILENO, msg, strlen(msg));
msg = " if no argument is given, the command is interpreted as";
write(STDOUT_FILENO, msg, strlen(msg));
msg = " exit 0.\n";
write(STDOUT_FILENO, msg, strlen(msg));
}
/**
 * help_help - display help information on the shell by builtin command
 */
void help_help(void)
{
char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "\n help [BUILTIN NAME]\n\tSee specific information on each ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "builtin command.\n";
write(STDOUT_FILENO, msg, strlen(msg));
}
/**
 * help_alias - display alias information on the shell by builtin command
 */
void help_alias(void)
{
char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "\n\talias: Prints a list of all aliases, one per line, in ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
write(STDOUT_FILENO, msg, strlen(msg));
msg = " the aliases name, name2, etc. one per line, in the ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: defines";
write(STDOUT_FILENO, msg, strlen(msg));
msg = " an alias for each NAME whose VALUE is given. If NAME ";
write(STDOUT_FILENO, msg, strlen(msg));
msg = "is already an alias, replace its value with VALUE.\n";
write(STDOUT_FILENO, msg, strlen(msg));
}
