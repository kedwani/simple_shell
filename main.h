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

void interactive(char **buf, size_t *n);
void _strtok(char *buf, char *argv[]);
<<<<<<< HEAD
char *_strstr(char *mainStr, char *sub);
int _strcmp(char *s1, char *s2);
=======
>>>>>>> 8cc4d5c34fdc9c1dceeef4dbed44b54625017ff6

extern char **environ;






#endif
