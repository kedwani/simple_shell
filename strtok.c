#include "main.h"

void _strtok(char *buf, char *argv[])
{
	int i = 2;

	argv[1] = strtok(buf, " ");
	while ((argv[i] = strtok(NULL, " ")))
		++i;
}
