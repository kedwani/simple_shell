#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	char command[1024];
	write(STDOUT_FILENO,"($)",3);
	read(STDIN_FILENO,command,1024);
	printf("you have entered >> %s", command);
	return (0);
}
