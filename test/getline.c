#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(size_t argc, char *argv[])

{
/*	size_t i;*/
	getline (&argv[1],&argc,stdin);
	printf("%s",argv[0]);
	printf("%s",argv[1]);
	printf("%lu",argc);

	return (0);
}
/* ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/
