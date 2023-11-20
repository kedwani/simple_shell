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
