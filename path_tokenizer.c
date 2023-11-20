#include "main.h"
/**
 * ath_tokinizer- Tokenize the PATH environment variable
 * and attempt to execute the command.
 *
 * This function takes the value of the PATH environment variable,
 * tokenizes it, and appends the command name to each token.
 * It then checks if the resultingpath exists using the stat system call.
 * If a valid path is found, it executes the command using the _excute
 * function and returns 1. If no valid path is found, it returns 0.
 *
 * Return: 1 if the command is successfully executed, 0 otherwise.
 */
int path_tokinizer(void)
{
	int i;

/* Copy the value of PATH to var.tt*/
	strcpy(var.tt, var.tmp);
	i = 1;

/*Tokenize the path and store in var.path*/
	var.path[0] = strtok(var.tt, ":");
	while ((var.path[i] = strtok(NULL, ":")))
		i++;

/*Free the allocated memory for var.tmp*/
	free(var.tmp);

/*Iterate through each path and check if the command exists*/
/* Build the full path by appending command to each path*/
	for (i = 0; var.path[i] != NULL; ++i) {
		strcpy(var.t, var.path[i]);
		strcat(var.t, "/");
		strcat(var.t, var.command[0]);

		if (stat(var.t, &var.statbuf) == 0) {
			_excute(var.t, var.command);
			return 1;
		}
	}

/*Return 0 if no valid path is found*/
    return 0;
}
