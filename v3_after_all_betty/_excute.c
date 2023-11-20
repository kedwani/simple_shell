#include "main.h"
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
