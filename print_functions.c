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
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned and errno set appropriately
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
* print_s - prints a string
* @s: string to be printed
*
* Return: number of characters printed
*/
int print_s(char *s)
{
int i = 0;

while (s[i] != '\0')
{
_putchar(s[i]);
i++;
}

return (i);
}
