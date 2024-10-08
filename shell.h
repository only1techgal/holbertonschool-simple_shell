#ifndef SHELL_H
#define SHELL_H

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


extern char **environ;
extern void (*signal(int sig, void (*handler)(int)))(int);

/*int checker(char **cmd, char *buf);*/
void prompt_user(void);
void handle_signal(int m);
char **tokenizer(char *line);
char test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);
void print_env(void);

int _strcmp(char  *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s, char *s2, int n);
char *_strdup(char *s);
char *strchr(const char *s, int c);
void execution(char *cp, char **cmd);
char *find_path(void);


void free_buffers(char **buf);


#endif /*SHELL_H*/
