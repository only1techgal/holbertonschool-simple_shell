#include "shell.h"

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


