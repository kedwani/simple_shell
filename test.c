#include "main.h"
/**
 * main - function of a simple shell program.
 *
 * This function is the entry point for the shell program, responsible for
 * initializing the program's variables and entering an infinite loop to
 * continuously read and execute commands until the program is terminated.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @envp: An array of strings representing the environment variables.
 *
 * Return: The exit status of the shell program.
 */

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

/**
 * srch- Search for the executable path of a given command and execute it.
 *
 * This function searches for the executable path of a specified command in the
 * environment's PATH variable. If found, it sets the command's full path,
 * otherwise, it sets an appropriate exit status to indicate an error.
 *
 * Return: 0 on success or a specific exit status on failure.
 */
int srch(void)
{
	int i;
	char **env = environ;
/*search for path and get it's value*/
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
/*tokinize the path and excute if command is found*/
	if (var.tmp != NULL)
		if (path_tokinizer() == 1)
			return (0);
/*error handeler*/
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
/**
 * tokenizer- tokinizei input buffer to extract command and arguments.
 *
 * This function takes the input buffer,
 * removes the trailing newline character,
 * and tokenizes it using space (' ') as the delimiter.
 * The resulting tokens are stored in the global variable var.command.
 * It also checks for built-in commands like 'exit' and 'env',
 * executing them or calling the 'srch' function
 * for other commands accordingly.
 *
 * Return: 0 on success and command execution, or specific
 * exit statuses for built-in commands.
 */
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
/**
 * _excute - Execute a command using the execve system call.
 *
 * This function forks a child process and attempts to execute the specified
 * command using the execve system call. If the execution fails, it prints an
 * error message and exits the child process with a status code. The parent
 * process waits for the child to complete and updates the global variable
 * var.status with the child's exit status.
 *
 * @name: The path to the command or executable.
 * @command: An array of strings representing the command and its arguments.
 * Return: 0 on successful execution, or an appropriate exit status in case
 * of errors.
 */
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

/**
 * path_tokinizer- Tokenize the PATH environment variable and
 * attempt to execute the command.
 *
 * This function takes the value of the PATH environment variable,
 * tokenizes it, and appends the command name to each token.
 * It then checks if the resulting path exists using the stat system call.
 * If a valid path is found, it executes
 * the command using the _excute function and returns 1.
 * If no valid path is found, it returns 0.
 *
 * Return: 1 if the command is successfully executed, 0 otherwise.
 */
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
