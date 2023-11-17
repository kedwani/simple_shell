#include "main.h"

int main(int argc, char *argv[], char *envp[])
{
	pid_t child;
	char *buf = NULL;
	size_t n = 0;
	int status = 0, i = 0;
	char *argu[1024];
	(void) argc;
	(void) envp;
/*	(void) argv; */
	while (1)
	{
		if (isatty(STDIN_FILENO))
			interactive(&buf, &n);
		else
			if (getline(&buf, &n, stdin) == -1)
			{
				free(buf);
				exit(0);
			}
	    /* remove the enter space>>\n*/
		for (i = 0; buf[i] != '\0'; ++i)
			if (buf[i] == '\n')
				buf[i] = '\0';

		_strtok(buf, argu);
		if (argu[0] == NULL)
			continue;
		if (strcmp("exit", argu[0]) == 0)
		{
			free(buf);
			exit(WEXITSTATUS(status));
		}
		if (strcmp("env", argu[0]) == 0)
		{
			printenv();
			free(buf);
			continue;
		}
		child = fork();
		if (child == -1)
		{
			perror("fork failed");
			free(buf);
			exit(0);
		}
		else if (child == 0)
		{
			if (execve(argu[0], argu, environ) == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
				free(buf);
				exit(STDERR_FILENO);
			}
		}
		else
			wait(&status);
	}
	free(argu);
	free(buf);
	return	(0);
}
