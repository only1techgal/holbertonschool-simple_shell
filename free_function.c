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
 * free_buffer - freesbuffer
 * @buf: buffer to be freed
 *
 * Return: nothing
 */
void free_buffers(char **buf)
{
int i = 0;

if (buf || buf == NULL)
return;
while (buf[i])
{
free(buf[i]);
i++
}
free(buf);
}


