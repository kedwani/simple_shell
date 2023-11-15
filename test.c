#include "main.h"

int main(int argc, char *argv[])
{
    pid_t child;
    char *buf = NULL;
    size_t n = 0;
    int status;
    (void) argc;

    while (1)
    {
	    if (isatty (STDIN_FILENO))
	    {
		    printf("$ ");
		    if (getline(&buf, &n, stdin) == -1)
		    {
			    perror("getline fail");
			    exit(EXIT_FAILURE);
		    }
	    }
	    else
		    if (getline(&buf, &n, stdin) == -1)
			    exit(EXIT_FAILURE);

        /* remove the enter space>>\n*/
        buf[strcspn(buf, "\n")] = 0;

        /*exit */
        if ((strstr(buf,"exit")) != NULL)
	{
            break;
        }
	child = fork();
        if (child == -1)
	{
		perror("fork failed");
		free(buf);
		exit(EXIT_FAILURE);
        }
	else if (child == 0)
	{
            _strtok(buf, argv);
            if (execve(argv[0], argv, NULL) == -1)
	    {
		if (buf[0] == '\n' || buf[0] == '\0' || buf[0] == 13 || is_only_spaces(buf))
		{
			free(buf);
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("%s: command not found\n", buf);
			free(buf);
			exit(EXIT_FAILURE);
		}
            }
        }
	else
		wait(&status);
    }

    free(buf);
    return 0;
}
