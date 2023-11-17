#include "main.h"

int main(int argc, char *argv[], char *envp[])
{
	pid_t child = 0;
	char *buf = NULL;
	size_t n = 0;
	int status= 0;
	char *argu[1024];
	(void) argc;
	(void) envp;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			interactive(&buf, &n);
		else
			if (getline(&buf, &n, stdin) == -1)
				exit(0);
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
			continue;
		}
		path(argu, argv, child,status);
		free(buf);
	}
	free(buf);
	return (0);
}


void path(char **argu, char **argv, pid_t child,int status)
{
        int i;
        char **env = environ;
        char *tmp = NULL, *t = malloc(400);
        char * path[1024];
	struct stat statbuf;

	for (i = 0; env[i] != NULL; ++i)
		if (strncmp("PATH=", env[i], 5) == 0)
                        tmp = strchr(env[i], '/');
        _strttok(tmp, path);
        for (i = 0; path[i] != NULL; ++i)
        {
                strcpy(t, path[i]);
                strcat(t, "/");
                strcat(t, argu[0]);
		if (stat(t, &statbuf) == 0)
                {
			child = fork();
			if (child == 0)
			{
				strcpy(argu[0], t);
				free(t);
				execve(argu[0], argu, environ);
			}
			else
			{
				wait(&status);
				free(t);
				return;
			}
		}
        }
	free(t);
	if ((execve(argu[0], argu, environ)) == -1)
	{
		printf("%s: No such file or directory\n", argv[0]);
		status = 512;
	}
	return;
}
void _strttok(char *tmp, char **path)
{
        int i= 1;
        char *t = malloc(1024);
        strcpy(t, tmp);
        path[0] = strtok(t, ":");
	while ((path[i] = strtok(NULL, ":")))
                i++;
	free(t);
}
