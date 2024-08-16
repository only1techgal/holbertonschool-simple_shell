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
* print_env - prints the environment string to stdout
*
* Return: 0
*/
void print_env(void)
{
int x = 0;
char **env = environ;

while (env[x])
{
write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
write(STDOUT_FILENO, "\n", 1);
x++;
}
}
