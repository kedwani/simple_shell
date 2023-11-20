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
void printenv(void);
int srch(void);
int g_line(void);
int _excute(char*, char**);
int path_tokinizer(void);


extern char **environ;

struct info
{
	pid_t child;
	char *command[100];
	int status;
	char *buf;
	size_t n;
	char **argv;
	char *tmp;
        char *path[100];
        struct stat statbuf;
        char t[1022];
        char tt[1024];
	int f;


};

struct info var;





#endif
