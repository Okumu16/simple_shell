#ifndef MAIN_H
#define MAIN_H

#define CMDMAX 1024         /* The maximum length a command can have */
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>         /* contains fork() */
#include <sys/types.h>      /* contains pid_t struct */
#include <sys/wait.h>       /* contains wait */


void display_prompt(const char *prompt);
char *get_command(char *cmd, FILE *stream);


#endif /* MAIN_H */
