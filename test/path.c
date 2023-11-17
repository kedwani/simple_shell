#include "main.h"
void srch(char** argv)
{
	int i;
	char **env = environ;
	char *tmp=NULL;
	char ** path = NULL;
	char *cur_path =NULL;

	for (i = 0;env[i] != NULL;++i)
		if (strncmp("PATH=",env[i],5) = 0)
			tmp = strchr(env,'=');
	tmp = strcat(tmp,":./");
	_strtok(tmp,path);
	for (i=0;path[i] != NULL;++i)
	{
		cur_path=strcat(path[i],argv[1]);
		if (state (cur_path) == 0)
		{
			argv[1]=cur_path
			excute(argv);
		}
	}
}
