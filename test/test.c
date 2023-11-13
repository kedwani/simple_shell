#include "main.h"

extern char ** environ;

int main (void)
{
	int j, status;
	pid_t check;
/**/
	char *line = NULL;
	size_t line_size;
	int i = 1;
        char *argv[3];

	printf("$ ");
	getline(&line,&line_size,stdin);

	argv[0] = strtok(line," ");
        while ((argv[i]= strtok(NULL," ")))
                ++i;


	char **env = environ;
/**/
		check =fork();
		if (check == 0)
		{
			j = execve(argv[0],argv,env);
			printf("error file not found : %d \n",j);
		}
		else
		{
			wait(&status);
			main();
		}

	return (0);

}
