#include "main.h"


int main(int argc, char *argv[], char *envp[])
{
	pid_t child;
	char *buf = NULL;
	size_t n = 0;
	int status = 0, i = 0;
	char *argu[9];
	(void) argc;
	(void) envp;
	(void) argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO,"$ ",2);
			if (getline(&buf, &n, stdin) == -1)
			{
				perror("getline fail");
				exit(0);
			}
		}
	else
		if (getline(&buf, &n, stdin) == -1)
			exit(0);

	    /* remove the enter space>>\n*/
		for (i = 0; buf[i] != '\0'; ++i)
			if (buf[i] == '\n')
				buf[i] = '\0';
		/*_strtok(buf, argv);
		if (argv[1] == NULL)
			continue;
		if (_strcmp("exit", argv[1]) == 0)
		{
			free(buf);
			exit(WEXITSTATUS(status));
		}
		*/
		child = fork();
		if (child == -1)
		{
			perror("fork failed");
			free(buf);
			exit(0);
		}
		else if (child == 0)
		{

			/*for (i = 0; argv[i + 1] != NULL; ++i)
		{
			argu[i] = argv[i + 1];
		}
			*/
			argu[0]=buf;
			argu[1] = NULL;
			if (execve(buf, argu, environ) == -1)
			{
				/*printf("%s: No such file or directory\n", argv[0]);*/
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
