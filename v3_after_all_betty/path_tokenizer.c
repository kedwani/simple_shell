#include "main.h"
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
