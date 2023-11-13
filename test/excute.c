#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(size_t argc, char *argv[])

{
	int r,i = 2;
	size_t j
	char *buf;
	gitline(&buf,&j);
/**
 *
*/
	argv[1]= strtok(buf," ");
	while (argv[i]= strtok(NULL," "))
		++i;
	for (i=0;argv[i] != NULL;++i)
		printf("%s\n",argv[i]);

	dprintf(STDOUT_FILENO,"trying to excute another prog\n");

2

	char *arg[] = {"int_to_binary_converter",NULL};
	if ( execve("int_to_binary_converter", arg, NULL) == -1)
		printf("i cannot excute the fucking prog\n");
	return (0);
}
/* ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/
