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
* find_path - finds the path from the global enviroment
* Return: NULL if path is not found or path if path is found.
*/
char *find_path(void)
{
int x;
char **env = environ, *path = NULL;

while (*env)
{
if (_strncmp(*env, "PATH=", 5) == 0)
{
path = *env;
while (*path && x < 5)
{
path++;
x++;
}
return (path);
}
env++;
}
return (NULL);
}
