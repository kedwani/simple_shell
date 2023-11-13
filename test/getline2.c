#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(size_t argc, char *argv[])

{
	int r;
	char buf[1024];
	write(STDOUT_FILENO,"$ ",2);
	r = read(STDIN_FILENO,buf,1023);
	buf[r] = '\0';
	dprintf(STDOUT_FILENO,"%s",buf);
	return (0);
}
/* ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/
