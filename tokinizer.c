#include "main.h"

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
