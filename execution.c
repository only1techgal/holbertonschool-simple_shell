#include "shell.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 * execution - executes commands entered by the users
 * @cp: command
 * @cmd: array pointer to command
 *
 * Return: 0
 */
void execution(char *cp, char **cmd)
{
pid_t child_pid;
int status;
char **env = environ;

child_pid = fork();
if (child_pid < 0)
perror(cp);
if (child_pid == 0)
{
execve(cp, cmd, env);
perror(cp);
free(cp);
free_buffers(cmd);
exit(98);
}
else
wait(&status);
}
~
