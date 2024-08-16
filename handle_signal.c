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
 *handle_signal- it keeps track is interactive mode
 *@m: the signal number
 *Return: nothing
 */

void handle_signal(int m)
{
(void)m;
write(STDERR_FILENO, "\n", 1);
write(STDERR_FILENO, "$ ", 2);
}
