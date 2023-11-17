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
#include <sys/types.h>

void rd_line(void);
void tokenizer(void);
void printenv (void);
void srch(void);
void g_line(void);
void _excute (void);
void _strtok(char*,char**);
extern char **environ;

struct info
{
	pid_t child;
	char *command[100];
	int status ;
	char *buf;
	size_t n;
	char **argv;
};

struct info var;
void _free(void);





#endif
