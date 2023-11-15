#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

void _strtok(char *buf, char *argv[]);

void _strtok(char *buf, char *argv[])
{
	int i = 1;
	argv[0]= strtok(buf," ");
	while ((argv[i]= strtok(NULL," ")))
		++i;
}
