#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execution(char *cp, char **cmd);

int main(void)
{
    char *input = NULL;
    size_t len = 0;
    char *token;
    char *argv[100];
    int argc = 0;

    printf("Simple Shell > ");
    getline(&input, &len, stdin);
    input[strcspn(input, "\n")] = '\0';

    token = strtok(input, " ");
    while (token != NULL)
    {
        argv[argc] = token;
        argc++;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    execution(argv[0], argv);

    free(input);

    return 0;
}
