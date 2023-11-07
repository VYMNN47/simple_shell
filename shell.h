#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"

extern char **environ;

/*Main functions*/
char *get_input(void);
char **tokenizer(char *line);
void free2d(char **str);
int _exec(char **cmd, char **av, int counter);
char *get_env(char *variable);
char *get_path(char *cmd);
void printerr(char *name, int counter, char *cmd);

/*String functions*/
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_itoa(int n);
void string_rev(char *string, int length);
char *_strtok(char *str, char *delim);
char *_strchr(char *s, char c);

#endif
