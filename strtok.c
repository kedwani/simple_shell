#include "main.h"

void _strtok(char *buf, char *argu[])
{
	int i = 1;
	/* remove the enter space>>\n*/
	for (i = 0; buf[i] != '\0'; ++i)
		if (buf[i] == '\n')
			buf[i] = '\0';
	argu[0] = strtok(buf, " ");
	while ((argu[i] = strtok(NULL, " ")))
		++i;
}
