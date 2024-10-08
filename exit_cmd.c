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

/** */

/**
 * exit_cmd - command to exit
 * @command: tokenized command
 * @line: input read from stdin
 *
 * Return: none.
 */
void exit_cmd(char **command, char *line)
{
free(line);
free(*command);
exit(0);
}


