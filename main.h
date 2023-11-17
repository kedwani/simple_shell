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
#include <sys/stat.h>

void interactive(char **buf, size_t *n);
void _strtok(char *buf, char *argv[]);
char *_strstr(char *mainStr, char *sub);
int _strcmp(char *s1, char *s2);
void printenv (void);
void _strttok(char *tmp,char **path);
int path(char **argu,char **argv,pid_t child );

extern char **environ;






#endif
