#include "main.h"
int main(int argc, char *argv[], char *envp[])
{
	var.status = 0;
	int i=0;
	(void) argc;
	(void) envp;
	var.argv = argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			rd_line();
		else
			g_line();
	}
	return(var.status);
}

int srch(void)
{
        int i;
        char **env = environ;
        char *tmp = NULL;
        char * path[100]={0};
        struct stat statbuf;
	char t[1022];
	char tt[1024];

	for (i = 0;env[i] != NULL;++i)
	{
/*		printf("inside env [%d] equal to %s \n",i,env[i]);
 */
		if (strncmp("PATH=",env[i],5) == 0)
		{
			if(strchr(env[i],'/'))
				tmp= strdup(strchr(env[i],'/'));
			else
			{
				var.status=127*256;
			}
				break;
		}
	}
/*	printf("outside env equal : k%sk\n",env[0]);*/

	if (env == NULL || strcmp(env[0],"SHLVL=0") == 0 )
	{
		var.status=127*256;
	}
	if (var.command[0][0] == '/' || var.command[0][0] == '.')
	{
		var.status = 0;
	}
	else
	{
		var.status=127*256;

	}
	if (tmp != NULL && tmp != "")
	{
		strcpy (tt,tmp);
		i= 1;
		path[0] = strtok(tt,":");
		while ((path[i] = strtok(NULL,":")))
			i++;
		free(tmp);
		/*	if(path[0]== NULL)
			printf("asdsad");
			exit(0);
		*/
		for (i = 0;path[i] != NULL;++i)
		{
			strcpy(t,path[i]);
			strcat(t,"/");
			strcat(t,var.command[0]);
			if (stat(t,&statbuf) == 0)
			{
				/*	strcpy(var.command[0],t);*/
				/*for(i=0;var.command[i] != NULL;++i)
				  printf("koko\n%s\nkoko\n",var.command[i]);
				*/
				/*		free(var.argv);*/
				_excute(t,var.command);
				return(0);
			}
		}
	}
	if (var.status == 256 * 127)
	{
		dprintf(STDERR_FILENO,"%s: 1: %s: not found\n",var.argv[0],var.command[0]);
		return(0);
	}

	if (stat(var.command[0],&statbuf) == 0 && (var.command[0][0] == '/' || var.command[0][0] == '.'))
	{
/*		free(var.argv);*/
		_excute(var.command[0],var.command);
		return (0);
	}
	var.status = 512;
	printf("%s: No such file or directory\n",var.argv[0]);

/*free(var.argv);*/
	return(0);
}

int rd_line (void)
{
	printf("$ ");

        if (getline(&var.buf, &var.n, stdin) == -1)
        {
		free(var.buf);
		perror("getline failed");
		exit(0);
        }
	tokenizer();
	return(0);
}
int tokenizer(void)
{
        int j = 1,i;
	for (i = 0; var.buf[i] != '\0'; ++i)
		if (var.buf[i] == '\n')
			var.buf[i] = '\0';

/*	printf("%s\n",var.buf);*/

        var.command[0] = strtok(var.buf, " ");
        while ((var.command[j] = strtok(NULL, " "))!= NULL)
                ++j;
/*	for (i=0;var.command[i] != NULL;++i)
		printf("%s\n",var.command[i]);
*/
/*	free(var.buf);*/
	if (var.command[0] == NULL)
	{
		return(0);
	}
	if (strcmp("exit", var.command[0]) == 0)
	{
		free(var.buf);
		exit(WEXITSTATUS(var.status));
	}
	if (strcmp("env", var.command[0]) == 0)
	{
		printenv();
		return(0);
	}
	srch();
	return(0);
}

int g_line (void)
{
	if (getline(&var.buf, &var.n, stdin) == -1)
	{
		free(var.buf);
		exit(WEXITSTATUS(var.status));
	}
	tokenizer();
	return(0);
}
int _excute (char *name, char **command)
{

	var.child = fork();
	if (var.child == 0)
	{
		/*	write(STDOUT_FILENO,name,strlen(name));
		write(STDOUT_FILENO,command[0],strlen(name));
		write(STDOUT_FILENO,command[1],strlen(name));
		write(STDOUT_FILENO,command[2],strlen(name));
		*/

		if (execve(name, command, environ) == -1);
		{
			printf("%s: No such file or directory\n",var.argv[0]);
			free(var.buf);
			exit(2);
		}
	}
	else
		wait(&var.status);
/*	free(var.argv);*/
	return(0);
}
