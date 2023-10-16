#ifndef _SHELL1_
#define _SHELL1_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

extern char **environ;

char *strincat(char *destin, char *sourc);
int strinlength(const char *s);
int strincmp(char *strA, char *strB);
int strinncmp(const char *strA, const char *strB, size_t length);
char *strindup(char *str);
int str2int(char *s);
int _putchar(char c);
void _enter(char *str);
void *re_alloc(void *pointr, unsigned int old_sz, unsigned int new_sz);
int cnt_inpt(char *str);
int cnt_delim(char *str, char *delim);
char *rm_nw_lin(char *string);
void sig_handler(int sign_id);
void openHelp(void);
void prnt_environ(void);
void exit_handle(char **melody, char *lin_e);
int execute_builtins(char **melody, char *lin_e);
void freeget_environ(char *environ_pth);
void free_tkns(char **tokns);
int exec(char *cmd_nme, char **opt_s);
char *get_env(const char *nme);
char **get_toki(char *str, char *delim, int length);
char *fd_cmd(char *cmd_nme);

#endif
