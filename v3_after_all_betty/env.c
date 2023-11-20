#include "main.h"
/**
 * printenv - Print the contents of the environment variables.
 *
 * This function iterates through the environment variables and prints each
 * variable along with its value to the standard output. It uses the global
 * variable `environ`,
 * which is an array of strings representing the environment.
 *
 * The function prints each environment variable on a new line until it reaches
 * the end of the environment variables.
 */
void printenv(void)
{
	int i = 0;
	char **env = environ;
/*Iterate through the environment variables and print each one*/
	while (env[i])
	{
		printf("%s\n", env[i]);
		++i;
	}
}
