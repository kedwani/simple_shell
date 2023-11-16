#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>


void _strtok(char *buf, char *argv[]);
char *_strstr(char *mainStr, char *sub);
int is_only_spaces(const char *str);
int _strcmp(char *s1, char *s2);

extern char **environ;






#endif