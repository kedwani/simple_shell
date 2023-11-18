#include "main.h"

void _strtok(char *buf, char *argu[])
{
	int i = 1;

	argu[0] = strtok(buf, " ");
	while ((argu[i] = strtok(NULL, " ")))
		++i;
}
