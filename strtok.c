#include "main.h"

void _strtok(char *buf, char *argv[])
{
	int i = 1;
	argv[0]= strtok(buf," ");
	while ((argv[i]= strtok(NULL," ")))
		++i;
}
