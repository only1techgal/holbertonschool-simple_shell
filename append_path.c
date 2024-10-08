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
* _strlen - return the length of a string
* @text: string
* Return: integer length of text
 */

int _strlen(char *text)
{
int count = 0;
int i;

for (i = 0; text[i] != '\0'; i++)
{
count++;
}
return (count);
}

/**
 * append_path - adds path to command
 * @path: path of command
 * @command: user entered command
 *
 * Return: buffer containing comand with path on success
 * NULL on failure
 */
char *append_path(char *path, char *command)
{
char *buf;
size_t i = 0, j = 0;

if (command == 0)
command = "";

if (path == 0)
path = "";

buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
if (!buf)
return (NULL);

while (path[i])
{
buf[i] = path[i];
i++;
}
if (path[i - 1] != '/')
{
buf[i] = '/';
i++;
}
while (command[j])
{
buf[i + j] = command[j];
j++;
}
buf[i + j] = '\0';
return (buf);
}
