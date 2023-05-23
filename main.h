#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_ARGS 100
#define BUFFER_SIZE 128

char **input_to_cmd(char *line);
void execute(char *filename, char **cmd, int line);
int _strcmp(const char *s1, const char *s2);
int _putchar(int c);
int _strlen(const char *str);
void myprintf(char *format, ...);
void print_int(int value);
void exit_handler(char *line);
int env_handler(char *line, char **env);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int path_handler(char **command, int flag);
char *str_cpy(char *dest, const char *src);
char *str_dup(const char *str);
char *str_cat(char *dest, const char *src);

#endif
