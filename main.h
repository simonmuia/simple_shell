#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stddef.h>

#define MAX_ARGS 100
#define READ_SIZE 1024


char **input_to_cmd(char *line);
void execute(char *filename, char **cmd, int line);
int _strcmp(const char *s1, const char *s2);
int _putchar(int c);
size_t _strlen(const char *str);
void myprintf(char *format, ...);
void print_int(int value);
void exit_handler(char *line);
int env_handler(char *line, char **env);
int path_handler(char **command, int flag);
char *str_cpy(char *dest, const char *src);
char *str_dup(const char *str);
char *str_cat(char *dest, char *src);
void myrllc(void *pt, size_t osize, size_t nsize);
void *mymemcpy(void *dest, const void *src, size_t n);

#endif
