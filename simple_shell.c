#include "main.h"

int main(int argc ,char *argv[])
{
	pid_t child;
	char *buf;
	size_t n, gl;
	int status, ex;
	(void) argc;

	printf("$ ");
	gl = (getline(&buf,&n,stdin));
	if (gl == -1) {
	perror("getline failed");
	free(buf);
	exit(EXIT_FAILURE);
	} 
	child = fork();
	if (child == -1) {
        perror("fork failed");
	free(buf);
        exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		_strtok(buf,argv);
		ex = execve(argv[0],argv,NULL);
		if (ex == -1)
		{
			perror("execve fiald");
			free(buf);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		child = wait(&status);
		main(argc ,argv);
	}
	return (0);
}
