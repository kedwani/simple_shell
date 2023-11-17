#include "main.h"
int main(int argc, char *argv[], char *envp[])
{
	struct info var;
	var.status = 0;

	int i = 0;
	(void) argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			rd_line();
		else
			g_line();
		return	(0);
	}
}

void srch(void)
{
        int i;
        char **env = environ;
        char *tmp=NULL;
        char * path [1024];
        char *cur_path =NULL;
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

	_strtok(tmp,path);

	for (i = 0;path[i] != NULL;++i)
		printf("%s\n",path[i]);

	for (i = 0;path[i] != NULL;++i)
        {
		t = malloc(1024);
		strcpy(t,path[i]);
		strcat(t,"/");
		strcat(t,var.command[0]);
		printf("%s\n",t);

		if (stat(t,&statbuf) == 0)
                {
			printf("ana hena ");
                        var.command[0]=t;
			free(t);
			_excute();
		}
	}

	free(t);
	main(0,var.argv,environ);
}

void rd_line (void)
{
	printf("$ ");
        if (getline(&var.buf, &var.n, stdin) == -1)
        {
		perror("getline failed");
		exit(0);
        }
	tokenizer();

}
void tokenizer()
{
        int i = 1;
/*remove \n */
	for (i = 0; var.buf[i] != '\0'; ++i)
		if (var.buf[i] == '\n')
			var.buf[i] = '\0';

        var.command[0] = strtok(var.buf, " ");
        while ((var.command[i] = strtok(NULL, " ")))
                ++i;
	if (var.command[0] == NULL)
		main(0,var.argv,environ);
	if (strcmp("exit", var.command[0]) == 0)
	{
		free(var.buf);
		exit(WEXITSTATUS(var.status));
	}
	if (strcmp("env", var.command[0]) == 0)
	{
		printenv();
		main(0,var.argv,environ);
	}
	srch();

		}

void printenv()
{
	int i =0;
	char **env = environ;
	while (env[i])
	{
		printf("%s\n",env[i]);
		++i;
	}
}
void g_line (void)
{
	if (getline(&var.buf, &var.n, stdin) == -1)
	{
		free(var.buf);
		exit(0);
	}
	tokenizer();
}
void _excute (void)
{
	var.child = fork();
	if (var.child == -1)
	{
		perror("fork failed");
		exit(0);
	}
	else if (var.child == 0)
	{
		if (execve(var.command[0], var.command, environ) == -1)
		{
			printf("%s: No such file or directory\n", var.argv[0]);
			free(var.buf);
			exit(STDERR_FILENO);
		}
	}
	else
		wait(&var.status);
}
void _strtok(char *tmp,char **path)
{
	int i= 1;
	char *t = tmp;
	path[0] = strtok(t,":");
	while (path[i] = strtok(NULL,":"))
		i++;
}
void _free(void)
{
	int i;
	for (i = 0;var.command[i]!=NULL;++i)
		free(var.command[i]);

}
