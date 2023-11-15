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
			    perror("getline failed");
			    free(buf);
			    exit(EXIT_FAILURE);
		    }
	    }
	    else
		    if (getline(&buf, &n, stdin) == -1)
			    exit(EXIT_FAILURE);
	    
        /* remove the enter space>>\n*/
        buf[strcspn(buf, "\n")] = 0;

        /*exit */
        if ((strcmp(buf,"exit")) == 0)
	{
            break;
        }

        /* space check*/
/*
	if (all_whitespace(buf))
		continue;
*/

/**/
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
		    perror("execve failed");
		    free(buf);
		    exit(EXIT_FAILURE);
            }
        }
	else
		wait(&status);
    }

    free(buf);
    return 0;
}

int all_whitespace(const char *str)
{
    while (*str != '\0') {
        if (!isspace((char)*str)) {
            return 0;/* NOT space*/
        }
        str++;
    }
    return 1;
}
