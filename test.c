#include "main.h"

int main(int argc, char *argv[], char *envp[])
{
	pid_t child = 0;
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
			continue;
		}
		status = path(buf,argu,argv,child);
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


int path(char *buf,char **argu,char **argv,pid_t child)
{
        int i,status = 0;
        char **env = environ;
        char *tmp=NULL;
        char * path [1024];
	struct stat statbuf;
        char *t;

	for (i = 0;env[i] != NULL;++i)
	{
                if (strncmp("PATH=",env[i],5) == 0)
                {
                        tmp = strchr(env[i],'/');
                        break;
                }
        }

        strcat(tmp,":.");
        _strttok(tmp,path);

        for (i = 0;path[i] != NULL;++i)
        {
                t = malloc(1024);
                strcpy(t,path[i]);
                strcat(t,"/");
                strcat(t,argu[0]);

                if (stat(t,&statbuf) == 0)
                {
			child = fork();
			if (child == -1)
			{
				perror("fork failed");
				free(buf);
				exit(0);
			}
			else if (child == 0)
			{
				strcpy(argu[0],t);
				if (execve(argu[0], argu, environ) == -1)
				{
					printf("%s: No such file or directory\n", argv[0]);
					free(buf);
					exit(STDERR_FILENO);
				}
			}
			else
				wait(&status);
			break;
		}
        }

	free(t);
	return(status);
}
void _strttok(char *tmp,char **path)
{
        int i= 1;
        char *t = malloc(1024);
        strcpy(t, tmp);
        path[0] = strtok(t,":");
	while ((path[i] = strtok(NULL,":")))
                i++;
	free(t);
}
