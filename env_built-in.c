#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * parse - tokenizes
 * @command: command from the user
 * @envp: enviroment path
 */

void parse(char command[])
{
char *arguments[11];
char *token = strtok(command, " ");
int arg_count = 0;


while (token != NULL && arg_count < 10)
{
arguments[arg_count++] = token;
token = strtok(NULL, " ");
}
if (arg_count > 11)
{
perror("Error: Too many arguments");
return;
}
arguments[arg_count] = NULL;
if (arg_count > 0)
{
execution(arguments[0], arguments);
}
}

/**
 * print_env - Prints the current environment variables.
 *
 * Return: Nothing (void)
 */
void print_env(void)
{
char **env = environ;

while (*env)
{
printf("%s\n", *env);
env++;
}
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found
 *         to be less than, to match, or be greater than s2, respectively.
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}
return (*s1 - *s2);
}

/**
 * main - Entry point for the simple shell.
 *
 * Return: always 0 (Success).
 */
int main(void)
{
char *input = NULL;
size_t len = 0;
ssize_t nread;

while (1)
{
printf("$ ");
nread = getline(&input, &len, stdin);

if (nread == -1)
{
free(input);
exit(0);
}

input[strcspn(input, "\n")] = '\0';

if (_strcmp(input, "env") == 0)
{
print_env();
}
else if (_strcmp(input, "exit") == 0)
{
free(input);
exit(0);
}
else
{
parse(input);
}

free(input);
input = NULL;
}
return (0);
}
