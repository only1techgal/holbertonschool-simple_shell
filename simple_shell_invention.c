#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *execution - A function creates a new process
 *to execute a command specifies by cmd.
 *@cp: Additional configuration or parameters.
 *@cmd: Array of command arguments. The first element is the command,
 *followed by its arguments.
 *
 *Return: The fuction does not return a value
 */
void execution(char *cp, char **cmd)
{
pid_t pid;
int status;

pid = fork();

if (pid == -1)
{
perror("Error: fork failed");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(cmd[0], cmd) == -1)
{
perror("Error: exec failed");
exit(EXIT_FAILURE);
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(STATUS) && !WIFSIGNALED(status));
}
}
}
