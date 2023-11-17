#include "main.h"
void printenv (void)
{
	int i;
	char ** env = environ;

	if (env)
		for(i=0;env[i]!= NULL;++i)
			printf("%s\n",env[i]);
	else
		printf("SHLVL=0\n");
}
