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
#include <signal.h>


int rd_line(void);
int tokenizer(void);
void printenv (void);
int srch(void);
int g_line(void);
int _excute (char*,char**);


extern char **environ;

struct info
{
	pid_t child;
	char *command[100];
	int status;
	char *buf;
	size_t n;
	char **argv;
};

struct info var;





#endif
