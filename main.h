#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_ARGS 100
char **input_to_cmd(char *line);
void execute(char *filename, char **cmd, int line);

#endif

