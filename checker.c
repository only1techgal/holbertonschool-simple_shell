#include "shell.h"

/**
 * checker - checks to see if its a build in fuction
 * @cmd: tokenized user input
 * @buf: line from the getline fuction
 *
 * Return: 1 if cmd executed, 0 if is not executed
 */
 int checker(char **cmd, char *buf)
{
if (handle_builtin(cmd, buf))
return (1);
else if (**cmd == '/')
{
execution(cmd[0], cmd);
return (1);
}
return (0);
}
