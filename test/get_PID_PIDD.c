#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	pid_t my_pid;
	my_pid = getpid();
	printf("my pid is : %u\n", my_pid);
	my_pid = getppid();
	printf("my parent pid is :%u\n", my_pid);
	return (0);
}
