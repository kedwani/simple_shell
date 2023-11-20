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

/**
 * struct info - Structure to hold information of shell variables.
 *
 * The `info` structure includes the following fields:
 * @child: A process ID
 * @command: An array of strings to store command and its arguments.
 * @status: An integer to store the status of the last executed command.
 * @buf: A string to store the input line read from the terminal.
 * @n: A size_t variable representing the
 * size of the allocated memory for `buf`.
 * @argv: A pointer to an array of strings
 * representing the command-line arguments.
 * @tmp: A pointer to a character array used for temporary storage.
 * @path: An array of strings to store
 * different directories in the PATH environment variable.
 * @statbuf: A structure to store file information.
 * @t: A character array used for temporary storage.
 * @tt: A character array used for temporary storage.
 *
 */
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
};

struct info var;





#endif
