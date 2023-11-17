include "main.h"
void printenv (void)
{
	int i;
	char ** env = NULL;

	env = environ;
	if (env)
		for(i=0;env[i]!= NULL;++i)
			printf("%s\n",env[i]);
}
