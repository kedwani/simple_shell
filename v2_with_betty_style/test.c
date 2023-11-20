#include "main.h"
int main(int argc, char *argv[], char *envp[])
{
	var.status = 0;
	(void) argc;
	(void) envp;
	var.argv = argv;
	var.tmp = NULL;

	while (1)
	{
/* check is input is terminal or not */
		if (isatty(STDIN_FILENO))
			rd_line();
		else
			g_line();
	}
	return (var.status);
}

int srch(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i] != NULL; ++i)
	{
		if (strncmp("PATH=", env[i], 5) == 0)
		{
			if (strchr(env[i], '/'))
				var.tmp = strdup(strchr(env[i], '/'));
			else
				var.status = (127 * 256);
			break;
		}
	}
	if (env == NULL || strcmp(env[0], "SHLVL=0") == 0)
		var.status = (127 * 256);
	if (var.command[0][0] == '/' || var.command[0][0] == '.')
		var.status = 0;
	else
		var.status = (127 * 256);
	if (var.tmp != NULL)
		if (path_tokinizer() == 1)
			return (0);
	if (var.status == 256 * 127)
	{
		dprintf(STDERR_FILENO, "%s: 1: %s: not found\n",
			var.argv[0], var.command[0]);
		return (0);
	}
	if (stat(var.command[0], &var.statbuf) == 0 &&
	    (var.command[0][0] == '/' || var.command[0][0] == '.'))
	{
		_excute(var.command[0], var.command);
		return (0);
	}
	var.status = 512;
	printf("%s: No such file or directory\n", var.argv[0]);
	return (0);
}

int tokenizer(void)
{
	int j = 1, i;
/*to remove the enter key  from input*/
	for (i = 0; var.buf[i] != '\0'; ++i)
		if (var.buf[i] == '\n')
			var.buf[i] = '\0';
/*tokenize the input */
	var.command[0] = strtok(var.buf, " ");
	while ((var.command[j] = strtok(NULL, " ")) != NULL)
		++j;
	if (var.command[0] == NULL)
		return (0);
/*built in commands*/
	if (strcmp("exit", var.command[0]) == 0)
	{
		free(var.buf);
		exit(WEXITSTATUS(var.status));
	}
	if (strcmp("env", var.command[0]) == 0)
	{
		printenv();
		return (0);
	}
	srch();
	return (0);
}

int _excute(char *name, char **command)
{
	var.child = fork();
	if (var.child == 0)
	{
		if (execve(name, command, environ) == -1)
		{
			printf("%s: No such file or directory\n", var.argv[0]);
			free(var.buf);
			exit(2);
		}
	}
	else
		wait(&var.status);
	return (0);
}
int path_tokinizer(void)
{
	int i;

	strcpy(var.tt, var.tmp);
	i = 1;
	var.path[0] = strtok(var.tt, ":");
	while ((var.path[i] = strtok(NULL, ":")))
		i++;
	free(var.tmp);
	for (i = 0; var.path[i] != NULL; ++i)
	{
		strcpy(var.t, var.path[i]);
		strcat(var.t, "/");
		strcat(var.t, var.command[0]);
		if (stat(var.t, &var.statbuf) == 0)
		{
			_excute(var.t, var.command);
			return (1);
		}
	}
	return (0);
}
