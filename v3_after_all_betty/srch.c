#include "main.h"
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
