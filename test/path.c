int i;
char **env = environ;
char *path=NULL;

for (i = 0;env[i] != NULL;++i)
        if (strncmp("PATH=",env[i],5) = 0)
                path = strchr(env,'=');
