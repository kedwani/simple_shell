#include "main.h"
int main(int argc ,char *argv[])
{
	pid_t child;
	char *buf;
	size_t n;
	int status;

	(void) argc;

/*start the command line */
	printf("$ ");
	getline(&buf,&n,stdin);

	child = fork();
	if (child == 0)
/*i am in the child now */
	{

		_strtok(buf,argv);
		execve(argv[0],argv,NULL);
	}
	else
/*i am in the parent*/
	{
		child = wait(&status);
		main(argc ,argv);
	}

	return (0);
}
/*
{
	pid_t pid;

	int r,i = 2;
	char buf[1024];
	write(STDOUT_FILENO,"$ ",2);
	r = read(STDIN_FILENO,buf,1023);
	buf[r] = '\0';
	argv[1]= strtok(buf," ");
	while (argv[i]= strtok(NULL," "))
		++i;
	for (i=0;argv[i] != NULL;++i)
		printf("%s\n",argv[i]);





	pid = fork();
	printf("after fork\n");
	if (pid == 0)
		printf("ahln ana el child \n");
	else
		printf("ahln ana el father \n");


	return (0);
}
 ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/
