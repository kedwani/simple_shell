#include "main.h"
void printenv()
{
 	int i =0;
        char **env = environ;
	while (env[i])
        {
                printf("%s\n",env[i]);
                ++i;
        }
}
